#include "populationbase.ih"

Maps PopulationBase::fittest(size_t n)
{
    if (n == size())       // Nothing to do
        return m_maps;


    Maps maps(m_maps);     // Create copy of maps
    std::sort(maps.begin(), maps.end(), compareMaps(*this)); // sort maps by fitness

    // Let's make sure we don't extend our reach
    auto end = maps.end();
    if (n < size())
        end = maps.begin() + n;

    return Maps(maps.begin(), end);
}
