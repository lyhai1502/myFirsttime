#include "Header.h"
using namespace std;

//--------------- NODE ----------------
// Xoa vinh vien con tro Node
void deleteNode(Node *&p)
{
    p->next = NULL;
    delete p;
    p = NULL;
}
// Khoi tao mot node co gia tri
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// --------------- STACK ----------------
// Khoi tao ngan xep
stackNode createStack()
{
    stackNode s;
    s.head = NULL;
    return s;
}
// Kiem tra ngan xep co dang rong?
int isStack_Empty(stackNode s)
{
    if (s.head == NULL)
        return 1;
    else
        return 0;
}
// Them phan tu moi vao ngan xep (them vao DAU danh sach)
void pushStack(stackNode &s, int value)
{
    Node *node = createNode(value);
    if (isStack_Empty(s))
        s.head = node;
    else
    {
        node->next = s.head;
        s.head = node;
    }
}
// Xoa phan tu cua ngan xep (xoa o DAU danh sach) va tra ve gia tri phan tu do
int popStack(stackNode &s)
{
    if (isStack_Empty(s))
        return 0; // Khong co phan tu de lay
    Node *p = s.head;
    int data = s.head->value;
    s.head = s.head->next;
    deleteNode(p);
    return data;
}
// Dem so luong phan tu trong ngan xep
int countStack(stackNode s)
{
    if (isStack_Empty(s))
        return 0;
    int count = 0;
    for (Node *p = s.head; p != NULL; p = p->next)
        count++;
    return count;
}
// In cac gia tri phan tu trong ngan xep
void printStack(stackNode s)
{
    for (Node *p = s.head; p != NULL; p = p->next)
        cout << p->value << " ";
}

// ------------------ QUEUE -----------------
// Khoi tao hang doi
queueNode createQueue()
{
    queueNode q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}
// Kiem tra hang doi co dang rong?
int isQueue_Empty(queueNode q)
{
    if (q.head == NULL)
        return 1;
    else
        return 0;
}
// Them phan tu moi vao hang doi (them vao CUOI danh sach)
void enQueue(queueNode &q, int value)
{
    Node *node = createNode(value);
    if (isQueue_Empty(q))
    {
        q.head = node;
        q.tail = node;
    }
    else
    {
        q.tail->next = node;
        q.tail = node;
    }
}
// Xoa phan tu cua hang doi (xoa o DAU danh sach)
int deQueue(queueNode &q)
{
    if (isQueue_Empty(q))
        return 0; // Khong co phan tu de lay
    Node *p = q.head;
    int data = q.head->value;
    q.head = q.head->next;
    deleteNode(p);
    if (q.head == NULL)
        q.tail = NULL;
    return data;
}
// In cac phan tu cua hang doi
void printQueue(queueNode q)
{
    for (Node *p = q.head; p != NULL; p = p->next)
        cout << p->value << " ";
}

/* *************************************************** */
// Khao sat do uu tien cua toan tu
int Priority(char x)
{
    if (x == '+' || x == '-')
        return 0;
    else if (x == '*' || x == '/')
        return 1;
    else
        return 2;
}
// Chuyen doi TRUNG TO sang HAU TO
char *infixToPostfix(char *infix)
{
    char *postfix = new char;
    stackNode allOperators = createStack();
    char token;
    int indexInfix, indexPostfix = 0;
    for (indexInfix = 0; infix[indexInfix] != '\0'; indexInfix++)
    {
        token = infix[indexInfix];
        if (token - '0' >= 0 && token - '0' <= 9)
            postfix[indexPostfix++] = token;
        else
        {
            while (!isStack_Empty(allOperators) && (Priority(token) <= Priority((char)(allOperators.head->value + '0'))))
                postfix[indexPostfix++] = (char)(popStack(allOperators) + '0');
            pushStack(allOperators, (int)token - '0');
        }
    }
    while (!isStack_Empty(allOperators))
        postfix[indexPostfix++] = (char)(popStack(allOperators) + '0');
    postfix[indexPostfix] = '\0';
    return postfix;
}
// Chuyen doi CHAR* sang STRING
string convertToString(char *a)
{
    string s = "";
    for (int i = 0; i < strlen(a); i++)
        s = s + a[i];
    return s;
}
// Chuyen doi STRING sang CHAR*
char *convertToChar(string a)
{
    char *c = new char;
    for (int i = 0; i < a.size(); i++)
        c[i] = a[i];
    return c;
}
// Chuyen doi TIEN TO sang HAU TO
char *prefixToPostfix(char *prefix)
{
    string str_prefix = convertToString(prefix);
    stack<string> postfix;
    int lengthPrefix = str_prefix.size();
    for (int i = lengthPrefix - 1; i >= 0; i--)
    {
        if (str_prefix[i] - '0' < 0 || str_prefix[i] - '0' > 9)
        {
            string token1 = postfix.top();
            postfix.pop();
            string token2 = postfix.top();
            postfix.pop();
            string tmp = token1 + token2 + str_prefix[i];
            postfix.push(tmp);
        }
        else
            postfix.push(string(1, str_prefix[i]));
    }
    return convertToChar(postfix.top());
}
// Chuyen doi HAU TO sang TIEN TO
char *postfixToPrefix(char *postfix)
{
    string str_postfix = convertToString(postfix);
    stack<string> s;
    int length = str_postfix.size();

    for (int i = 0; i < length; i++)
    {
        if (str_postfix[i] - '0' < 0 || str_postfix[i] - '0' > 9)
        {
            string token1 = s.top();
            s.pop();
            string token2 = s.top();
            s.pop();
            string tmp = str_postfix[i] + token2 + token1;
            s.push(tmp);
        }
        else
            s.push(string(1, str_postfix[i]));
    }

    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return convertToChar(ans);
}
// Kiem tra cap ngoac co cung loai hay khong
bool sameBracketType(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    return false;
}
// Kiem tra xau co hop le
bool checkBracketPairs(char *c)
{
    stackNode s = createStack();
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{')
            pushStack(s, (int)c[i]);
        else if (c[i] == ')' || c[i] == ']' || c[i] == '}')
        {
            if (isStack_Empty(s) || sameBracketType(s.head->value, c[i]))
                return false;
            else
                int x = popStack(s);
        }
        if (!isStack_Empty(s))
            return false;
        return true;
    }
