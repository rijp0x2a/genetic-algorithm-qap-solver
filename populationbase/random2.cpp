#include "populationbase.ih"

size_t PopulationBase::random(size_t size) const
{
    return static_cast<size_t>(random() * size);
}
