#include "Source.cpp"
using namespace std;

int main()
{
    // BAI 1: Chuyen doi trung to (infix) sang hau to (postfix)
    char infix[] = "1+5*3-4+8/2";
    char *c = infixToPostfix(infix);
    cout << "INFIX: ";
    printCharArray(infix);
    cout << " -> POSTFIX: ";
    printCharArray(c);

    // BAI 2: Chuyen doi tien to (prefix) sang hau to (postfix) va nguoc lai
    char infix[] = "";
    return 0;
}