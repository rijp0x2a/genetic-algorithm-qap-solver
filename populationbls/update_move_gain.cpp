#include "populationbls.ih"

void PopulationBLS::update_move_gain(PlacementMap &individual, size_t i, size_t j)
{
    // Update the delta/fitness gain/move gain matrix for the swap i, j
    for (size_t k = 0; k < m_qap.size; ++k)
        for (size_t l = k+1; l < m_qap.size; ++l) {
            if (k != i && k != j && l != i && l != j)
                m_move_gain[k][l] = compute_delta_part(individual, i, j, k, l);
            else
                m_move_gain[k][l] = compute_delta(individual, k, l);
        }
}
