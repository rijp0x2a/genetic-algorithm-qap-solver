#ifndef INCLUDED_POPULATIONBASE_H
#define INCLUDED_POPULATIONBASE_H

#include "../placementmap/placementmap.h"
#include "../QAP/QAP.h"

#include <string>
#include <vector>

typedef std::vector<PlacementMap> Maps;

class PopulationBase
{
    struct compareMaps
    {
        PopulationBase const &m_pop;
        compareMaps(PopulationBase const &pop);
        bool operator()(PlacementMap const &lhs, PlacementMap const &rhs) const;
    };

protected:
    std::string             m_name;
    Maps                    m_maps;
    QAP                     m_qap;
    int                     m_elitism;              // # elitism per it
    int                     m_tournament;           // tournament size
    double                  m_mutation = 0.015;

    // members
    void                    init(size_t size);      // Initialize
                                                    // Format time seconds
    std::string             formatSeconds(size_t s);

public:
    PopulationBase(std::string name, size_t size);

    size_t                  size() const;           // Returns size of the solution

    bool                    m_solution_found;

    // virtual methods
    virtual Maps            crossover();            // Crossover method
    virtual size_t          elitism(Maps &maps);    // Elitism method
    virtual void            evolve();               // Evolve population
                                                    // Evolve population n times
    virtual void            evolve(size_t n, size_t runtime);
    virtual int             fitness();              // Returns the fitness of fittest in population
    virtual PlacementMap   &fittest();              // Return fittest map
    virtual Maps            fittest(size_t n);      // Return n fittests
    virtual void            mutation();             // Update mutation rate
                                                    // Create offspring of parents
    virtual PlacementMap    offspring(const Maps &parents);
    virtual int             optimal() const;        // Returns QAP optimal solution
    virtual PlacementMap   &pick();                 // Random sample and pick fittest
    virtual double          random() const;         // Random generators
    virtual size_t          random(size_t size) const;
};

#endif
