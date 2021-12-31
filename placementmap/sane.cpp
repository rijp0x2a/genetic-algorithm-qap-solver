#include "placementmap.ih"

bool PlacementMap::sane() const
{
    std::vector<int> found(m_size);
    for (auto it = m_factories.begin(); it != m_factories.end(); ++it)
    {
        found[(*it) - 1] += 1;
    }

    bool sane = true;
    for (auto it = found.begin(); it != found.end(); ++it)
    {
        if ((*it) != 1)
        {
            std::cout << "Position " << it - found.begin() + 1 << " has " << (*it) << " occurences" << std::endl;
            sane = false;
        }
    }
    return sane;
}