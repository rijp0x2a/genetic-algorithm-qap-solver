#ifndef INCLUDED_POPULATIONUX_H
#define INCLUDED_POPULATIONUX_H

#include "../placementmap/placementmap.h"       // for PlacementMap
#include "../populationbase/populationbase.h"   // for Maps

template <typename PopulationType = PopulationBase>
class PopulationUX
:
    public PopulationType
{
public:
    PopulationUX(std::string name, size_t popSize);

    virtual PlacementMap    offspring(const Maps &parents) override;
};

#include "populationux1.inl"
#include "offspring.inl"

#endif
