#include "populationbls.ih"

int PopulationBLS::compute_delta(PlacementMap &individual, size_t i, size_t j)
{
    // Compute the delta/fitness gain/move gain for the swap i, j
    // This is faster than doing the actual swaps and calculating their new fitness.
    // O(n) instead of O(n^2)

    int index_i = individual[i]-1;
    int index_j = individual[j]-1;

    int delta;
    delta = (m_qap.flow[index_i][index_i] - m_qap.flow[index_j][index_j])
            * (m_qap.distance[j][j] - m_qap.distance[i][i])
            + (m_qap.flow[index_i][index_j] - m_qap.flow[index_j][index_i])
            * (m_qap.distance[j][i] - m_qap.distance[i][j]);

    for (size_t k = 0; k < m_qap.size; ++k) {
        int index_k = individual[k]-1;
        if (index_k != index_i && index_k != index_j)
            delta += (m_qap.flow[index_k][index_i] - m_qap.flow[index_k][index_j]) * (m_qap.distance[k][j] - m_qap.distance[k][i])
                    + (m_qap.flow[index_i][index_k] - m_qap.flow[index_j][index_k]) * (m_qap.distance[j][k] - m_qap.distance[i][k]);
    }
    return delta;
}