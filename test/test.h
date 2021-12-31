#ifndef INCLUDED_TEST_H
#define INCLUDED_TEST_H

#include <string>
#include <vector>

template <typename PopulationType>
struct Test {
    std::string name;
    size_t iterations;
    size_t runtime;
    size_t population;
    size_t runs;
    std::vector<PopulationType> results;
};

#endif