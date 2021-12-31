#include "populationbase.ih"

void PopulationBase::init(size_t size)
{
    Parser parser;
    m_qap = std::move(parser.parse(m_name));

    // next, fill m_maps with `size' PlacementMaps
    for (size_t idx = size; idx != 0; --idx)
    {
        m_maps.push_back(PlacementMap(m_qap, m_qap.size, true));
    }
}
