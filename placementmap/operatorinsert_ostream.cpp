#include "placementmap.ih"

std::ostream &operator<<(std::ostream &os, const PlacementMap &map)
{
    for (auto it = map.m_factories.begin(); it != map.m_factories.end(); ++it)
    {
        os << (*it) << ' ';
    }
    return os;
}
