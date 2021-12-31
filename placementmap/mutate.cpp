#include "placementmap.ih"

void PlacementMap::mutate(double mutationRate)
{
    for (auto it = m_factories.begin(); it != m_factories.end(); ++it)
    {
        double r = static_cast<double>(rand()) / RAND_MAX;
        if (r < mutationRate)
        {
            size_t idx1 = it - m_factories.begin();     // determine idx of position 1
                                                        // determine random position of 2
            r = static_cast<double>(rand()) / RAND_MAX;
            size_t idx2 = static_cast<size_t>(r * m_factories.size());
                                                        // WORKAROUND: Segfault MinGW
            if (idx2 == m_factories.size())             // on MinGW, this change is 1:32768
                --idx2;                                 // on OSX / Linux, 1:2.3 million

            int val1 = (*it);                           // remember old value of pos1

            m_factories[idx1] = m_factories[idx2];      // set pos1 to value of pos2
            m_factories[idx2] = val1;                   // set pos2 to old value of pos1
        }
    }
    fitness(true);  // recalculate fitness
}
