#include "populationbls.ih"

void PopulationBLS::decide_jump_magnitude()
{
    if (m_non_improving > m_max_non_improvement) {
        m_jump_magnitude = m_qap.size*(0.4 + (static_cast<double>(rand()%20)/100.0));
        m_non_improving = 0;
    } else if (m_descending_counter != 0 && m_fitness_last_descent != m_current_fitness) {
        // Search escaped from the previous local optimum, reinitialize jump magnitude
        m_non_improving++;
        m_jump_magnitude = std::ceil(m_qap.size*m_initial_jump_magnitude);
    } else if (m_current_fitness == m_fitness_last_descent) {
        // Search returned to the previous local optimum, increase jump magnitude by one
        m_jump_magnitude++;
    }
}