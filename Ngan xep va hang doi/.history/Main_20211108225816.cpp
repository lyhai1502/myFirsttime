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
    // Prefix to Postfix
    char prefix2[] = "*-1/23-/156";
    char *postfix2 = prefixToPostfix(prefix2);
    cout << "\nPREFIX: ";
    printCharArray(prefix2);
    cout << " -> POSTFIX: ";
    printCharArray(postfix2);

    // Postfix to Prefix
    char postfix3[] = "123/-15/6-*";
    char *prefix3 = postfixToPrefix(postfix3);
    cout << "\nPOSTFIX: ";
    printCharArray(postfix3);
    cout << " -> PREFIX: ";
    printCharArray(prefix3);

    // BAI 3: Kiem tra xau ngoac co hop le hay khong?
    char c[] = "[()][{()}]";
    cout << "\nXau ";
    printCharArray(c);
    cout << (checkBracketPairs(c) ? " : Hop le" : " : Khong hop le");

    char c[] = "[(]";
    cout << "\nXau ";
    printCharArray(c);
    cout << (checkBracketPairs(c) ? " : Hop le" : " : Khong hop le");

    return 0;
}