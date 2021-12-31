#include "populationbls.ih"

void PopulationBLS::random_perturb(PlacementMap &individual)
{
    // Do a random perturbation
    size_t i_min = random(m_qap.size-1);
    size_t j_min = random(m_qap.size-1);
    int temp = 0;

    if(i_min > j_min)
        temp = i_min;
        i_min = j_min;
        j_min = temp;

    // Find a swap which changes the fitness
    while(i_min == j_min or (m_current_fitness + m_move_gain[i_min][j_min]) == m_current_fitness)
    {
        j_min = random(m_qap.size-1);
        if(i_min > j_min)
            temp = i_min;
            i_min = j_min;
            j_min = temp;
    }
    apply_swap(individual, i_min, j_min);
}