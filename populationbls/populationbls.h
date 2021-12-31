#ifndef INCLUDED_POPULATIONBLS_H
#define INCLUDED_POPULATIONBLS_H

#include "../populationbase/populationbase.h"

class PopulationBLS
:
    public PopulationBase
{
    // members
    const int       m_bls_long_iterations = 10000; // Used for small number of individuals (for example offspring)
    const int       m_bls_short_iterations = 5000; // Used for the whole population
    const int       m_max_non_improvement = 15; // T max number of consecutive non-improvements in fitness

    Matrix          m_move_gain; // Delta
    Matrix          m_move_history; // H

    int             m_current_fitness;// C
    int             m_best_fitness; // Cbest
    int             m_fitness_last_descent; // Cp
    bool            m_descending;
    int             m_descending_counter;

    int             m_non_improving; // w counter for consecutive non-improving local optima

    const double    m_initial_jump_magnitude = 0.15; // 0.05n, 0.15n
    long double     m_jump_magnitude; // Number of perturb moves L

    int             m_iteration;

    const double    m_p0 = 0.75; // Smallest probability for applying directed purturbation
    const double    m_q = 0.3; // Probability for applying random over recency-base

    const double    e = 2.718;

    // tabu tenure rand[0.9n, 1.1n]
    const double    r1 = 0.9; // Directed perturbation parameters
    const double    r2 = 0.2; // 1.1 - 0.9

    double m_r1;
    double m_r2;

    // methods
    void            breakout_local_search(PlacementMap &individual, int num_iterations);
    void            initialize(PlacementMap &individual);

    // Delta/move gain methods
    void            initialize_move_gain(PlacementMap &individual);
    void            update_move_gain(PlacementMap &individual, size_t i, size_t j);
    int             compute_delta(PlacementMap &individual, size_t i, size_t j); // const;
    int             compute_delta_part(PlacementMap &individual, size_t i, size_t j, size_t r, size_t s); // const;

    // Swapping methods
    void            transpose(int &a, int &b) const;
    void            apply_swap(PlacementMap &individual, size_t i, size_t j);
    bool            apply_best_swap(PlacementMap &individual);

    // Perturbation methods
    void            perturbation(PlacementMap &individual);
    void            tabu_search_perturb(PlacementMap &individual);
    void            recency_perturb(PlacementMap &individual);
    void            random_perturb(PlacementMap &individual);
    void            decide_jump_magnitude();



public:

    PopulationBLS(std::string name, size_t size);
    virtual void evolve()                               override;           // Evolve population
    virtual void evolve(size_t size, size_t runtime)    override;           // Evolve population
};

#endif
