#include "populationbls.ih"

void PopulationBLS::evolve()
{
    PopulationBase::evolve();

    breakout_local_search(fittest(), m_bls_long_iterations);
}