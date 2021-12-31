#ifndef INCLUDED_PLACEMENTMAP_H
#define INCLUDED_PLACEMENTMAP_H

#include <iostream>
#include <iterator>
#include <vector>

#include "../QAP/QAP.h"

typedef std::vector<int>::const_iterator FactoryIterator;

class PlacementMap
{
    // members
    QAP                &m_qap;
    //double              m_mutationRate = 0.1; //0.015;
    size_t              m_size;
    std::vector<int>    m_factories;
    int                 m_fitness = -1;

    // methods
    void                init();                 // initializes factories on random locations
public:
    PlacementMap(QAP &qap);
    PlacementMap(QAP &qap, size_t mapSize, bool fill);
    PlacementMap(QAP &qap, std::vector<int> factories);
    PlacementMap(const PlacementMap &map);      // copy constructor
    PlacementMap(PlacementMap &&map);           // move constructor

    PlacementMap       &operator=(PlacementMap rhs);

    int                &operator[](const size_t idx);
    int                 operator[](const size_t idx) const;
    FactoryIterator     begin() const;
    FactoryIterator     end() const;
                                                // mutate by swap
    void                mutate(double mutationRate);
    int                 fitness() const;        // returns the calculated fitness
    int                 fitness(bool calc);     // calculates new fitness and returns
    size_t              size() const;           // returns the size of the map / solution
    bool                sane() const;           // checks whether all positions are present

    friend void         swap(PlacementMap &lhs, PlacementMap &rhs);
    friend std::ostream &operator<<(std::ostream &os, const PlacementMap &map);
};

#endif
