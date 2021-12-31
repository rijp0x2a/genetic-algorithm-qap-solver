#include "populationbls.ih"

PopulationBLS::PopulationBLS(std::string name, size_t size)
:
    PopulationBase(name, size)
{
    m_r1 = m_qap.size * r1;
    m_r2 = m_qap.size * r2;

    std::cout << "- Breakout Local Search" << std::endl;

    m_elitism = size - 2;

    std::cout << "Applying initial BLS to all individuals." << std::endl;

    for (auto it = m_maps.begin(); it != m_maps.end(); ++it) {
        std::cout << std::distance(m_maps.begin(), it) << " of " << m_maps.size() << "\r" << std::flush;
        breakout_local_search((*it), m_bls_short_iterations);
        if (m_solution_found)
            break;
    }

    std::cout << "Initialization done." << std::endl;
}
