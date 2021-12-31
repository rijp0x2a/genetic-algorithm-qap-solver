#include "populationbase.ih"

PlacementMap &PopulationBase::pick()
{
    size_t rSize = size() - 1;
    PlacementMap &fittest = m_maps[random(rSize)];
    for (size_t idx = m_tournament - 1; idx != 0; --idx)
    {
        size_t rndIdx = random(rSize);
        if (fittest.fitness() > m_maps[rndIdx].fitness())
            fittest = m_maps[rndIdx];
    }
    return fittest;
}
