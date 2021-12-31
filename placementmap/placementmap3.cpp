#include "placementmap.ih"

PlacementMap::PlacementMap(const PlacementMap &other)
:
    m_qap(other.m_qap),
    m_size(other.m_size),
    m_factories(other.m_factories),
    m_fitness(other.m_fitness)
{
    // empty
}
