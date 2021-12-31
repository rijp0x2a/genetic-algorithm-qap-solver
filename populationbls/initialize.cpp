#include "populationbls.ih"

void PopulationBLS::initialize(PlacementMap &individual)
{
    m_current_fitness = individual.fitness(); // C

    m_move_gain = Parser::generateEmptyMatrix(m_qap.size, m_qap.size);
    initialize_move_gain(individual); // delta matrix

    m_move_history = Parser::generateEmptyMatrix(m_qap.size, m_qap.size); // H

    m_fitness_last_descent = m_current_fitness; // Cp
    m_descending = false;
    m_descending_counter = 0;
    m_non_improving = 0; // w counter for consecutive non-improving local optima
    m_jump_magnitude = std::ceil(m_initial_jump_magnitude*m_qap.size); // Number of perturb moves L
    m_iteration = 0;
}
