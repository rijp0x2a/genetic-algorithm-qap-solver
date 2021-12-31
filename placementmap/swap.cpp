#include "placementmap.ih"

void swap(PlacementMap &lhs, PlacementMap &rhs)
{
    using std::swap;

    swap(lhs.m_fitness, rhs.m_fitness);
    swap(lhs.m_size, rhs.m_size);
    swap(lhs.m_qap, rhs.m_qap);
    swap(lhs.m_factories, rhs.m_factories);
}