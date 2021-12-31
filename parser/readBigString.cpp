#include "parser.ih"

string Parser::readBigString(string pathToFile) const
{
    ifstream in;
    in.open(pathToFile);
    if(!in.is_open()) {
        cerr << "Could not open file: " << pathToFile << endl;
        exit (EXIT_FAILURE);
    }

    string bigString;
    string tmp;
    while(!in.eof()) {
        getline(in, tmp);
        bigString = bigString + " " + tmp;
    }

    in.close();

    return bigString;
}
