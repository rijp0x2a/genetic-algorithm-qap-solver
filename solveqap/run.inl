template <typename PopulationType>
PopulationType SolveQAP<PopulationType>::run()
{
    cout << "Running " << m_name << " for " << iterations() << " iterations with population size of " << m_pop.size() << " (optimal fitness = " << m_pop.optimal() << ")" << endl;

    m_pop.evolve(m_itMax, m_runtime);
    m_pop.fittest().sane();

    cout << "Optimal fitness = " << m_pop.optimal() << endl;
    cout << "Final fitness   = " << m_pop.fitness() << endl;
    cout << "Final solution  = " << m_pop.fittest() << endl;
    cout << "Relative error  = " << round((m_pop.fitness() - m_pop.optimal()) / double(m_pop.fitness()) * 100.0 * 1000.0) / 1000.0 << "%" << endl;
    cout << endl;

    return m_pop;
}
