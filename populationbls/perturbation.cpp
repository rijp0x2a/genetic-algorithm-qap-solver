#include "populationbls.ih"

void PopulationBLS::perturbation(PlacementMap &individual)
{
    // Perturb the individual
    // The higher the non improving fitness counter the more random the perturbations.
    // Perturbation is the switching of the factories.

    double p = std::max(m_p0, pow(e, -static_cast<double>(m_non_improving/m_max_non_improvement)));

    bool directed_perturbation = false;

    // with probability P
    if (random() > p)
        directed_perturbation = true;

    for (int i = 0; i < m_jump_magnitude; i++) {
        if (m_solution_found)
            return;

        if (directed_perturbation) {
            // Directed perturbation (history and quality based)
            tabu_search_perturb(individual);
        } else {
            // Random perturbation
            random_perturb(individual);
        }
    }
    individual.fitness(true); // calculate fitness again
}
