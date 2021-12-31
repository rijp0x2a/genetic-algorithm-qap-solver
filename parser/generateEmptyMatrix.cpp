#include "parser.ih"

Matrix Parser::generateEmptyMatrix(size_t rows, size_t columns)
{
    vector<vector<int>> matrix(rows);
    for (size_t i = 0; i < rows; i++)
        matrix[i].resize(columns);

    return matrix;
}
