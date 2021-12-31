#include "populationbls.ih"

void PopulationBLS::transpose(int &a, int &b) const
{
    long temp = a;
    a = b;
    b = temp;
}
