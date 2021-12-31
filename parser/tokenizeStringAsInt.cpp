#include "parser.ih"

vector<int> Parser::tokenizeStringAsInt(string stringToTokenize)
{
    stringstream strstream(stringToTokenize);
    istream_iterator<int> it(strstream);
    istream_iterator<int> end;
    vector<int> tokenized(it, end);

    return tokenized;
}
