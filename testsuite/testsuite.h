#ifndef INCLUDED_TESTSUITE_H
#define INCLUDED_TESTSUITE_H

#include "../solveqap/solveqap.h"
#include "../test/test.h"

#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>
#include <string>
#include <vector>

template <typename PopulationType>
class TestSuite
{
    std::vector<Test<PopulationType>> m_tests;
public:
    void add(const std::string name, const size_t iterations, const size_t runs, const size_t populationSize);
    void add(const std::string name, const size_t iterations, const size_t runtime, const size_t runs, const size_t populationSize);
    void execute();
};

#include "add1.inl"
#include "add2.inl"
#include "execute.inl"

#endif
