#include "parser.ih"

void Parser::printMatrix(Matrix const &matrix)
{
    for (auto row = matrix.begin(); row != matrix.end(); ++row)
    {
        for (auto col = (*row).begin(); col != (*row).end(); ++col) {
            cout.width( 3 );
            cout << (*col) << " ";
        }
        cout << endl;
    }
}