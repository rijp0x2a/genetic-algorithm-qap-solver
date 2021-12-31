#include "populationbls.ih"

void PopulationBLS::breakout_local_search(PlacementMap &individual, int num_iterations)
{
    initialize(individual);

    // For each iteration
    for (m_iteration = 0; m_iteration != num_iterations; ++m_iteration) {

        m_descending_counter = 0;

        // Apply the best swap of factories
        // Keep applying the best swap until local optimum is reached
        m_descending = apply_best_swap(individual);
        while (m_descending && !m_solution_found){
            m_descending = apply_best_swap(individual);
            m_descending_counter++;
        }

        if (m_solution_found)
            return;

        // Determine the perturbation strength to be applied to individual
        decide_jump_magnitude();

        m_fitness_last_descent = m_current_fitness;

        // Perturb the current local optimum with perturbation moves
        perturbation(individual);
    }
}
