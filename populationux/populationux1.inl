#include "populationux.ih"

template <typename PopulationType>
PopulationUX<PopulationType>::PopulationUX(std::string name, size_t size)
:
    PopulationType(name, size)
{
    cout << "- Uniform Crossover" << endl;
}
