#include "placementmap.ih"

int PlacementMap::fitness(bool)
{
    int calculatedFitness = 0;
    for (auto row = m_factories.begin(); row != m_factories.end(); ++row) {
        for (auto col = m_factories.begin(); col != m_factories.end(); ++col) {
            size_t idx = static_cast<size_t>(row - m_factories.begin());
            size_t jdx = static_cast<size_t>(col - m_factories.begin());
            calculatedFitness += m_qap.flow[(*row) - 1][(*col) - 1] * m_qap.distance[idx][jdx];
        }
    }
    m_fitness = calculatedFitness;
    return m_fitness;
}
