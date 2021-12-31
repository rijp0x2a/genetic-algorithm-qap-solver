#include "populationbase.ih"

PopulationBase::PopulationBase(std::string name, size_t size)
:
    m_name(name),
    m_elitism(5),
    m_tournament(4),
    m_solution_found(false)
{
    init(size);     // initialize QAP
}
