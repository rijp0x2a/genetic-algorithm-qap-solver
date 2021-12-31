#include "populationpmx.ih"

template <typename PopulationType>
PlacementMap PopulationPMX<PopulationType>::offspring(const Maps &parents)
{
    // If i'm correct than this should be PMX crossover ;)
    const PlacementMap &parent1 = parents[0];
    const PlacementMap &parent2 = parents[1];

    PlacementMap child(PopulationType::m_qap, parent1.size(), false);
    std::vector<bool> occupied;
    occupied.assign(parent1.size(), false);
                                    // get crossover positions
    size_t startPos = PopulationType::random(parent1.size() - 1);
    size_t endPos = PopulationType::random(parent2.size() - 1);

    if (startPos > endPos)          // make sure our boundaries are proper
    {
        size_t temp = endPos;
        endPos = startPos;
        startPos = temp;
    }

    // step1: copy segment from parent 1
    for (size_t idx = startPos; idx != endPos; ++idx)
    {
        child[idx] = parent1[idx];
        occupied[idx] = true;
    }

    // step2: for same segment from parent 2 look for non-copied elements
    for (size_t idx = startPos; idx != endPos; ++idx)
    {
        bool found = false;
        for (size_t jdx = startPos; jdx != endPos; ++jdx)
        {
            if (child[jdx] == parent2[idx])
            {
                found = true;
                break;
            }
        }

        if (found)      // if it was already copied, move to the next
            continue;

        // determine where to place this non-copied element
        // find out which element is in it's place (from parent1)
        // and search for the position of that element in parent2.
        // that's our new position
        for (auto jit = parent2.begin(); jit != parent2.end(); ++jit)
        {
            size_t jdx = jit - parent2.begin();
            if (parent1[idx] == parent2[jdx])
            {
                // if the new space in child is already occupied,
                // we find out where that element is placed in parent2 and
                // finally put the new element on that position in child
                while (occupied[jdx])
                {
                    for (auto hit = parent2.begin(); hit != parent2.end(); ++hit)
                    {
                        size_t hdx = hit - parent2.begin();
                        if (child[jdx] == parent2[hdx])
                        {
                            jdx = hdx;
                            break;
                        }
                    }
                }
                child[jdx] = parent2[idx];
                occupied[jdx] = true;
                break;
            }
        }
    }

    // Finally, fill the remaining positions from parent 2
    for (auto it = occupied.begin(); it != occupied.end(); ++it)
    {
        size_t idx = it - occupied.begin();
        if (not (*it))      // not filled
        {
            child[idx] = parent2[idx];
            occupied[idx] = true;
        }
    }

    return child;
}
