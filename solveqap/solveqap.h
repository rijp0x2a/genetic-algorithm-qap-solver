#ifndef INCLUDED_SOLVEQAP_H
#define INCLUDED_SOLVEQAP_H

#include <string>

template <typename PopulationType>
class SolveQAP
{
    // members
    size_t          m_itMax;        // Holds max iterations; 0 is no max iterations
    size_t          m_runtime;      // Maximum runtime in seconds
    std::string     m_name;         // Holds name of the QAP problem
    PopulationType  m_pop;

    // methods
                                    // Print friendly iterations count
    const std::string   iterations() const;
public:
    SolveQAP(std::string name);
    SolveQAP(std::string name, size_t itMax, size_t runtime, size_t popSize);

    PopulationType  run();      // Performs calculation
};

#include <iostream>
#include <sstream>
#include <utility>
#include <math.h>

using namespace std;

#include "iterations.inl"
#include "run.inl"
#include "solveqap1.inl"
#include "solveqap2.inl"

#endif
