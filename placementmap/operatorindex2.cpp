#include "placementmap.ih"

int PlacementMap::operator[](const size_t idx) const
{
    return m_factories[idx];
}