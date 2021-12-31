#include "populationbase.ih"

double PopulationBase::random() const
{
    return static_cast<double>(rand()) / RAND_MAX;
}
