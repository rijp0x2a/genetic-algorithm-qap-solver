#ifndef INCLUDED_QAP_H
#define INCLUDED_QAP_H

#include <vector>

typedef std::vector<std::vector<int>> Matrix;

struct QAP {
    struct Solution {
        int                         optimal;
        std::vector<int>            permutation;
    };

    size_t      size;
    Matrix      flow;
    Matrix      distance;
    Solution    solution;
};

#endif