#include "placementmap.ih"

PlacementMap::PlacementMap(QAP &qap, size_t mapSize, bool fill)
:
    m_qap(qap),
    m_size(mapSize),
    m_factories(mapSize)
{
    if (fill) {
        init();
        fitness(true);
    }
}
