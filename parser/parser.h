#ifndef INCLUDED_PARSER_H
#define INCLUDED_PARSER_H

#include <string>
#include <vector>

#include "../QAP/QAP.h"

class Parser {
    // members
    std::string         m_dataDir;

    // methods
    std::string         readBigString(std::string pathToFile) const;
    std::vector<int>    tokenizeStringAsInt(std::string stringToTokenize);

public:
    Parser();
    Parser(const std::string dataDir);

    QAP                 parse(std::string file);
    static Matrix       generateEmptyMatrix(size_t rows, size_t columns);
    static void         printList(std::vector<int> const &list);
    static void         printMatrix(Matrix const &matrix);
};

#include "parser1.inl"
#include "parser2.inl"

#endif
