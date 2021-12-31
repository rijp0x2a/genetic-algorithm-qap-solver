#include "placementmap.ih"

PlacementMap::PlacementMap(PlacementMap &&other)
:
    m_qap(other.m_qap)
{
    swap(*this, other);
}
