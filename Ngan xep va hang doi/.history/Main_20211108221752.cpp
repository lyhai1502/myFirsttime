#include "Source.cpp"
using namespace std;

int main()
{
    char c[] = "[{()}]’";
    if (checkBracketPairs(c))
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}