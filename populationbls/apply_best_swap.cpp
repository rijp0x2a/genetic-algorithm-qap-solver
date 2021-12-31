#include "populationbls.ih"

bool PopulationBLS::apply_best_swap(PlacementMap &individual)
{
    size_t i_min = 0;
    size_t j_min = 0;
    int move_gain = INT_MAX;

    // Find the optimal swap
    for (size_t i = 0; i < m_qap.size; ++i) {
        for (size_t j = i+1; j < m_qap.size; ++j) {
            if (m_move_gain[i][j] < move_gain) {
                move_gain = m_move_gain[i][j];
                i_min = i;
                j_min = j;
            }
        }
    }

    // If it is improving our fitness, apply it.
    if (m_current_fitness + move_gain < m_current_fitness) {
        apply_swap(individual, i_min, j_min);
        return true;
    }
    return false;
}