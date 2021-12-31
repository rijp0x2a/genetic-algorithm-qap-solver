#include "placementmap.ih"

PlacementMap::PlacementMap(QAP &qap, std::vector<int> factories)
:
    m_qap(qap),
    m_size(factories.size()),
    m_factories(factories)
{
    fitness(true);
}
