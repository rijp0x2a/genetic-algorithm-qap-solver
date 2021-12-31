#include "populationmpx.ih"

template <typename PopulationType>
Maps PopulationMPX<PopulationType>::crossover()
{
    // Keep fittest parents
    Maps newMaps = PopulationType::fittest(PopulationType::m_elitism);

    // Generate new off spring using specified number of parents
    PlacementMap child = offspring(std::move( PopulationType::fittest(PopulationType::m_elitism) ));
    child.fitness(true); // recalculate fitness

    // Save offspring
    newMaps.push_back(child);

    return newMaps;
}
