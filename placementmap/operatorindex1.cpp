#include "placementmap.ih"

int &PlacementMap::operator[](const size_t idx)
{
    return m_factories[idx];
}