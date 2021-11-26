#include "Source.cpp"
using namespace std;

int main()
{
    // BAI 1: Chuyen doi trung to (infix) sang hau to (postfix)
    char infix[] = "1+5*3-4+8/2";
    char *c = infixToPostfix(infix);
    printCharArray(c);
    return 0;
}