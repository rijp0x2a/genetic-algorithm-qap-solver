#include "populationmpx.ih"

template <typename PopulationType>
PlacementMap PopulationMPX<PopulationType>::offspring(const Maps &parents)
{
    size_t numberOfFactories = parents[0].size();

    // MX / MPX - multiple parent crossover
    // mu = population size -> all parents used in crossover
    PlacementMap offSpring(PopulationType::m_qap, numberOfFactories, false);
    Matrix desirabilityMatrix = Parser::generateEmptyMatrix(numberOfFactories, numberOfFactories);

    // Fill desirability matrix with the probability of finding a specific gene at a certain position
    for (size_t i = 0; i != parents.size(); i++) {
        PlacementMap parent = parents[i];
        for (size_t j = 0; j != parent.size(); j++) {
            size_t factory = parent[j];
            desirabilityMatrix[j][factory - 1]++;
        }
    }

    // Index gene in a random way
    PlacementMap genePositions(PopulationType::m_qap, numberOfFactories, true);
    for (size_t i = 0; i != genePositions.size(); i++) {
        // Find most probably factory for this position
        size_t gene = genePositions[i];
        auto biggest = std::max_element(std::begin(desirabilityMatrix[gene - 1]), std::end(desirabilityMatrix[gene - 1]));

        size_t factory = std::distance(std::begin(desirabilityMatrix[gene - 1]), biggest) + 1;
        offSpring[gene - 1] = factory;

        // Factory has been placed, is not diserable anymore (aka cannot be placed again)
        for (size_t i = 0; i != numberOfFactories; i++) {
            desirabilityMatrix[i][factory - 1] = -1;
        }
    }

    return offSpring;
}
