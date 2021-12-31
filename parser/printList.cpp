#include "parser.ih"

void Parser::printList(vector<int> const &list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
        cout << (*it) << " ";
    cout << endl;
}