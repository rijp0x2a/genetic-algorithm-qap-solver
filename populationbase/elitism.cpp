#include "populationbase.ih"

size_t PopulationBase::elitism(Maps &maps)
{
    if (m_elitism > 0) {
        Maps &&elite = fittest(m_elitism);
        maps.insert(maps.end(), elite.begin(), elite.end());
    }
    return m_elitism;
}
