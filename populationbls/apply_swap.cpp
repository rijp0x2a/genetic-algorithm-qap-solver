#include "populationbls.ih"

void PopulationBLS::apply_swap(PlacementMap &individual, size_t i, size_t j)
{
     // Perform swap
    transpose(individual[i], individual[j]);

    // Update current fitness
    m_current_fitness += m_move_gain[i][j];

    // Update iteration number when move uv was last performed
    m_move_history[i][j] = m_iteration;
    update_move_gain(individual, i, j);

    if (m_current_fitness < m_best_fitness) {
        m_best_fitness = m_current_fitness;
        m_non_improving = 0;
    }

    // Check if we found the optimal solution
    if (m_current_fitness == m_qap.solution.optimal) {
        individual.fitness(true);
        m_current_fitness = individual.fitness();

        std::cout << std::endl;
        std::cout << "Final solution      = " << m_current_fitness << std::endl;
        std::cout << "Optimal solution    = " << m_qap.solution.optimal << std::endl;
        std::cout << "Final permuation    = " << individual << std::endl;

        // Determine if solution is equal (or reversed) to QAP solution
        bool is_equal = std::equal(individual.begin(), individual.end(), m_qap.solution.permutation.begin());
        bool is_requal = false;
        if (not is_equal)
            is_requal = std::equal(individual.begin(), individual.end(), m_qap.solution.permutation.rbegin());

        std::cout << "Permutation correct = " << std::boolalpha << (is_equal || is_requal);
        if (is_requal)
            std::cout << " (reversed)";
        std::cout << std::endl;

        m_solution_found = true;
    }
}

