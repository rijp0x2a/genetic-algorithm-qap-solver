#include "populationpmx.ih"

template <typename PopulationType>
PopulationPMX<PopulationType>::PopulationPMX(std::string name, size_t size)
:
    PopulationType(name, size)
{
    cout << "- Partially Matched Crossover" << endl;
}
