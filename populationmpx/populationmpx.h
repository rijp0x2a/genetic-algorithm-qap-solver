#ifndef INCLUDED_POPULATIONMPX_H
#define INCLUDED_POPULATIONMPX_H

#include "../placementmap/placementmap.h"
#include "../populationbase/populationbase.h"

template <typename PopulationType = PopulationBase>
class PopulationMPX
:
    public PopulationType
{
public:
    PopulationMPX(std::string name, size_t popSize);

    virtual PlacementMap    offspring(const Maps &parents)       override;
    virtual Maps            crossover()                          override;
    virtual void            evolve()                             override;
    virtual void            evolve(size_t n, size_t runtime)     override;
};

#include "populationmpx1.inl"
#include "crossover.inl"
#include "offspring.inl"
#include "evolve1.inl"
#include "evolve2.inl"

#endif
