#include "populationmpx.ih"

template <typename PopulationType>
PopulationMPX<PopulationType>::PopulationMPX(std::string name, size_t size)
:
    PopulationType(name, size)
{
    PopulationType::m_elitism = size;     // num of parents to use
    cout << "- Multiple Parent Crossover" << endl;
}
