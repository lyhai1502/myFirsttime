#include "Source.cpp"
using namespace std;

int main()
{
    // BAI 1: Chuyen doi trung to (infix) sang hau to (postfix)
    char infix[] = "1+5*3-4+8/2";
    char *postfix = infixToPostfix(infix);
    cout << "INFIX: ";
    printCharArray(infix);
    cout << " -> POSTFIX: ";
    printCharArray(postfix);

    // BAI 2: Chuyen doi tien to (prefix) sang hau to (postfix) va nguoc lai
    char prefix[] = "*-1/23-/156";
    char *postfix = prefixToPostfix(prefix);
    cout << "\nPREFIX: ";
    printCharArray(prefix);
    cout << " -> POSTFIX: ";
    printCharArray(postfix);
    return 0;
}