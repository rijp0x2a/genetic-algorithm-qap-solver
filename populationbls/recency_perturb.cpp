#include "populationbls.ih"

void PopulationBLS::recency_perturb(PlacementMap &individual)
{
    // Perform the least recently applied move

    size_t i_min = 0;
    size_t j_min = 0;
    int move_number = INT_MAX;

    for (size_t i = 0; i < m_qap.size; ++i) {
        for (size_t j = i+1; j < m_qap.size; ++j) {
            if(m_move_history[i][j] < move_number)
            {
                i_min = i;
                j_min = j;
                move_number = m_move_history[i][j];
            }
        }
    }
    apply_swap(individual, i_min, j_min);
}
