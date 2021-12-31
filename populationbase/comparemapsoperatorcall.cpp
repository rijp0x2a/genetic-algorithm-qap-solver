#include "populationbase.ih"

bool PopulationBase::compareMaps::operator()(PlacementMap const &lhs, PlacementMap const &rhs) const
{
    return lhs.fitness() < rhs.fitness();
}
