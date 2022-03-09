#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int *data;

public:
    Stack()
    {
        size = 0;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }
    ~Stack()
    {
        delete[] data;
    }
    void display()
    {
        {
            if (!size)
            {
                cout << "Stack is EMPTY!\n\n";
                return;
            }
        }
        cout << "(";

        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << ")";
    }
    void addElement(int value)
    {
        int *tmp = new int[size];
        for (int i = 0; i < size; i++)
            tmp[i] = data[i];
        size++;
        delete[] data;
        data = tmp;
        data[size - 1] = value;
    }
    void removeElement()
    {
        if (!size)
        {
            cout << "Nothing to remove!\n";
            return;
        }
        int *tmp = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
            tmp[i] = data[i];
        delete[] data;
        data = tmp;
        size--;
    }
    int top()
    {
        if (!size)
        {
            cout << "Nothing to take\n";
            return -1; // Khong co gi de lay
        }
        return data[size - 1];
    }
    bool isStackEmpty()
    {
        if (!size)
            return true;
        else
            return false;
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack s;
    s.addElement(2);
    cout << s.top();
    cout << s.getSize();

    return 0;
}