#include "populationux.ih"

template <typename PopulationType>
PlacementMap PopulationUX<PopulationType>::offspring(const Maps &parents)
{
    const PlacementMap &parent1 = parents[0];
    const PlacementMap &parent2 = parents[1];

    PlacementMap child(PopulationType::m_qap, parent1.size(), false);
    std::vector<bool> found;
    found.assign(parent1.size(), false);
                                // fill child genome where possible
    for (size_t idx = 0; idx != parent1.size(); ++idx)
    {
        if (PopulationType::random() > 0.5)
            child[idx] = parent1[idx];
        else
            child[idx] = parent2[idx];

        if (found[child[idx] - 1])  // value was already assigned earlier
            child[idx] = -1;    // non-possible value to replace later
        else
            found[child[idx] - 1] = true;
    }
    
    std::vector<int> available;
                                // determine still available genes
    for (auto it = found.begin(); it != found.end(); ++it)
    {
        if (not *it)
            available.push_back(it - found.begin());
    }

    size_t pos;                 // fill missing genes using available genes
    for (auto it = child.begin(); it != child.end(); ++it)
    {
        if ((*it) == -1)
        {
            pos = PopulationType::random(available.size() - 1);
            child[it - child.begin()] = available[pos] + 1;
            available.erase(available.begin() + pos);
        }
    }

    return child;
}
