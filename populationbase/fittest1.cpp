#include "populationbase.ih"

PlacementMap &PopulationBase::fittest()
{
    PlacementMap &fittest = (*m_maps.begin());
    for (auto it = m_maps.begin() + 1; it != m_maps.end(); ++it)
    {
        if (fittest.fitness() > (*it).fitness())
            fittest = (*it);
    }

    return fittest;
}