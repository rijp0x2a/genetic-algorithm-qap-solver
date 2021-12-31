#include "populationbls.ih"

void PopulationBLS::tabu_search_perturb(PlacementMap &individual)
{
    // Favors swaps that minimize fitness degradation with the constraint that the swap has not been applied
    // the last Y iterations. Y in this case is decided by the size of problem and a random value from a
    // given range called the tabu tenure.

    size_t i_min = 0;
    size_t j_min = 0;
    int move_gain = INT_MAX;

    // TODO
    // constexpr van m_qap.size * r1 && m_qap.size * r2

    for (size_t i = 0; i < m_qap.size; ++i) {
        for (size_t j = i+1; j < m_qap.size; ++j) {
            if((m_current_fitness + m_move_gain[i][j]) != m_current_fitness && m_move_gain[i][j] < move_gain &&
                    //((m_move_history[i][j] + m_qap.size * r1 + random(m_qap.size*r2)) < m_iteration or
                    ((m_move_history[i][j] + m_r1 + random(m_r2)) < m_iteration or
                            (m_current_fitness + m_move_gain[i][j]) < m_best_fitness))
            {
                i_min = i;
                j_min = j;
                move_gain = m_move_gain[i][j];
            }
        }
    }
    apply_swap(individual, i_min, j_min);
}
