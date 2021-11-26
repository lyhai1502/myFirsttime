#include <iostream>
#include <stack>
using namespace std;

// -------------- NODE --------------
struct Node
{
    int value;
    Node *next;
};

// Xoa vinh vien con tro Node
void deleteNode(Node *&p);

// Khoi tao mot node co gia tri
Node *createNode(int value);

// --------------- STACK ----------------
struct stackNode
{
    Node *head;
};

// Khoi tao ngan xep
stackNode createStack();

// Kiem tra ngan xep co dang rong?
int isStack_Empty(stackNode s);

// Them phan tu moi vao ngan xep (them vao DAU danh sach)
void pushStack(stackNode &s, int value);

// Xoa phan tu cua ngan xep (xoa o DAU danh sach) va tra ve gia tri phan tu do
int popStack(stackNode &s);

// Dem so luong phan tu trong ngan xep
int countStack(stackNode s);

// In cac gia tri phan tu trong ngan xep
void printStack(stackNode s);

// ------------------ QUEUE -----------------
struct queueNode
{
    Node *head;
    Node *tail;
};
// Khoi tao hang doi
queueNode createQueue();

// Kiem tra hang doi co dang rong?
int isQueue_Empty(queueNode q);

// Them phan tu moi vao hang doi (them vao CUOI danh sach)
void enQueue(queueNode &q, int value);

// Xoa phan tu cua hang doi (xoa o DAU danh sach)
int deQueue(queueNode &q);

// In cac phan tu cua hang doi
void printQueue(queueNode q);

/* ******************* BAI TAP ******************** */
// Chuyen doi CHAR* sang STRING
string convertToString(char *a);
// Chuyen doi STRING sang CHAR*
char *convertToChar(string a);
// Khao sat do uu tien cua toan tu
int Priority(char x);
// Chuyen doi TRUNG TO sang HAU TO
char *infixToPostfix(char *infix);
// Chuyen doi TIEN TO sang HAU TO
char *prefixToPostfix(char *prefix);
// Chuyen doi HAU TO sang TIEN TO
char *postfixToPrefix(char *postfix);
// Kiem tra cap ngoac co cung loai hay khong
bool sameBracketType(char open, char close);
// Kiem tra xau co hop le
bool checkBracketPairs(char *c);
