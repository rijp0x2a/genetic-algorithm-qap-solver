#include "populationbase.ih"

Maps PopulationBase::crossover()
{
    Maps newMaps;
    size_t elitismOffset = elitism(newMaps);

    for (auto it = m_maps.begin() + elitismOffset; it != m_maps.end(); ++it)
    {
        PlacementMap &parent1 = pick();
        PlacementMap &parent2 = pick();

        // create offspring for parents
        PlacementMap child = offspring({parent1, parent2});
        child.fitness(true); // calculate new fitness
        newMaps.push_back(child);
    }

    return newMaps;
}
