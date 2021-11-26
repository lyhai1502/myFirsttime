#include "Source.cpp"
using namespace std;

int main()
{
    // BAI 1: Chuyen doi trung to (infix) sang hau to (postfix)
    char infix1[] = "1+5*3-4+8/2";
    char *postfix1 = infixToPostfix(infix1);
    cout << "INFIX: ";
    printCharArray(infix1);
    cout << " -> POSTFIX: ";
    printCharArray(postfix1);

    // BAI 2: Chuyen doi tien to (prefix) sang hau to (postfix) va nguoc lai
    char prefix2[] = "*-1/23-/156";
    char *postfix2 = prefixToPostfix(prefix2);
    cout << "\nPREFIX: ";
    printCharArray(prefix2);
    cout << " -> POSTFIX: ";
    printCharArray(postfix2);
    return 0;
}