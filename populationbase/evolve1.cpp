#include "populationbase.ih"

void PopulationBase::evolve()
{
    // Crossover
    Maps &&new_maps = crossover();
    m_maps = std::move(new_maps);

    // =========================================================================== //
    // NOTE: original mutate function, has following issues:
    // - Mutation rate = 100% (every map mutates because the random calculation is done on the factory level instead of the map level
    // - May remove best solution
    //
    // ORIGINAL:

    // Determine mutation rate
    mutation();

    // Mutate some placement maps
    for (auto it = m_maps.begin(); it != m_maps.end(); ++it)
        (*it).mutate(m_mutation);

    // =========================================================================== //
}

