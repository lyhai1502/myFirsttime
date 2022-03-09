#include <iostream>
using namespace std;

class DynamicallyArray
{
private:
    int size;
    int *data;

public:
    DynamicallyArray()
    {
        size = 0;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    ~DynamicallyArray()
    {
        delete[] data;
    }

    int getElement(int pos)
    {
        return data[pos];
    }
    void setElement(int value, int pos)
    {
        data[pos] = value;
    }
    void display()
    {
        {
            if (!size)
            {
                cout << "Array is EMPTY!\n\n";
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
    void removeFirstElement()
    {
        if (!size)
        {
            cout << "Nothing to remove!\n";
            return;
        }
        int *tmp = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
            tmp[i] = data[i + 1];
        delete[] data;
        data = tmp;
        size--;
    }
    int SecondMaxValue()
    {
        if (size == 0 || size == 1)
            return -1;
        int max = data[0];
        int secondMax = data[1];
        int j = 2;
        while (secondMax == max)
            secondMax = data[j++];
        if (secondMax > max)
            swap(secondMax, max);
        for (int i = j; i < size; i++)
            if (max > data[i] && secondMax < data[i])
                secondMax = data[i];
            else if (max < data[i])
            {
                if (secondMax < data[i])
                    secondMax = max;
                max = data[i];
            }
        return secondMax;
    }
};

int main()
{
    DynamicallyArray tmp;
    tmp.display();
    return 0;
}