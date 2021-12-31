#include "populationmpx.ih"

template <typename PopulationType>
void PopulationMPX<PopulationType>::evolve()
{
    // Crossover
    Maps &&new_maps = crossover();
    PopulationType::m_maps = std::move(new_maps);

    // Add mutated entries to map
    Maps mutatedMaps;

    PopulationType::mutation();

    for (auto it = PopulationType::m_maps.begin(); it != PopulationType::m_maps.end(); ++it) {
        mutatedMaps.push_back(*it);
        PlacementMap mutated = PlacementMap(*it);
        mutated.mutate(PopulationType::m_mutation);

        if(mutated.fitness() != (*it).fitness()) { // If fitness changed
            mutatedMaps.push_back(mutated); // Do not lose original but add it back
        }
    }

    // Perform elitism
    PopulationType::m_maps = mutatedMaps;
    PopulationType::m_maps = PopulationType::fittest(PopulationType::m_elitism);
}

