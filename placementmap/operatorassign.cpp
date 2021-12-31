#include "placementmap.ih"

PlacementMap &PlacementMap::operator=(PlacementMap rhs)
{
    swap(*this, rhs);
    return *this;
}