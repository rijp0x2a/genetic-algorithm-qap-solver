#include "populationbls.ih"

int PopulationBLS::compute_delta_part(PlacementMap &individual, size_t i, size_t j, size_t r, size_t s)
{
    // Compute the partial delta/fitness gain/move gain. This is only possible when i, j, r, s are all different.

    int index_i = individual[i]-1;
    int index_j = individual[j]-1;
    int index_s = individual[s]-1;
    int index_r = individual[r]-1;

    return (m_move_gain[r][s]
            + (m_qap.flow[index_r][index_i] - m_qap.flow[index_r][index_j] + m_qap.flow[index_s][index_j] - m_qap.flow[index_s][index_i])
            * (m_qap.distance[s][i] - m_qap.distance[s][j] +  m_qap.distance[r][j] - m_qap.distance[r][i])
            + (m_qap.flow[index_i][index_r] - m_qap.flow[index_j][index_r] + m_qap.flow[index_j][index_s] - m_qap.flow[index_i][index_s])
            * (m_qap.distance[i][s] - m_qap.distance[j][s] +  m_qap.distance[j][r] - m_qap.distance[i][r])
    );
}
