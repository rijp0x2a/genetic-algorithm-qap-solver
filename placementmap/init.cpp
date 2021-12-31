#include "placementmap.ih"

void PlacementMap::init()
{
    // Fill m_size m_factories with random
    for (size_t idx = m_size; idx !=0; --idx)
        m_factories[idx - 1] = idx;

    std::random_device rd;
    std::mt19937 r(rd()); // random generator

    std::shuffle(m_factories.begin(), m_factories.end(), r);
}