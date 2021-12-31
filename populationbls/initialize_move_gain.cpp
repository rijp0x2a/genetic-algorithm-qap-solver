#include "populationbls.ih"

void PopulationBLS::initialize_move_gain(PlacementMap &individual)
{
    // Initialize the move gain matrix for the individual.
    // Compute only half the matrix due to symmetrical matrix.
    for (size_t i = 0; i < m_qap.size; ++i) {
        for (size_t j = i+1; j < m_qap.size; ++j) {
            m_move_gain[i][j] = compute_delta(individual, i, j);
        };
    };
}
