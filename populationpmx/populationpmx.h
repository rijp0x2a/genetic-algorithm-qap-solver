#ifndef INCLUDED_POPULATIONPMX_H
#define INCLUDED_POPULATIONPMX_H

#include "../placementmap/placementmap.h"
#include "../populationbase/populationbase.h"

template <typename PopulationType = PopulationBase>
class PopulationPMX
:
    public PopulationType
{
public:
    PopulationPMX(std::string name, size_t popSize);

    virtual PlacementMap    offspring(const Maps &parents) override;
};

#include "populationpmx1.inl"
#include "offspring.inl"

#endif
