#include "Header.h"

// Ham chuc nang
int Bai03(vector<int> arr, int n)
{
    // Chuyen bieu thuc co bien i va j tung ben rieng biet
    vector<int> sumArri_index;   // Tao mang Ai + |i^1.5|
    vector<int> minusArrj_index; // Tao mang Aj - canj
    for (int i = 0; i < n; i++)
    {
        sumArri_index.push_back(arr[i] + floor((i + 1) * (float)sqrt(i + 1)));
        minusArrj_index.push_back(arr[i] - ceil((float)sqrt(i + 1)));
    }

    int max = minusArrj_index[0];
    int min = minusArrj_index[0];
    for (int i = 0; i < n; i++)
    {
        if (minusArrj_index[i] > max)
            max = minusArrj_index[i]; // Maximum value in array
        else if (minusArrj_index[i] < min)
            min = minusArrj_index[i]; // Minimum value in array
    }

    int k = max - min + 1;
    vector<int> countMinusArr;
    for (int i = 0; i < k; i++)
        countMinusArr.push_back(0);

    for (int i = 0; i < n; i++)
        countMinusArr[minusArrj_index[i] - min]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += countMinusArr[sumArri_index[i] - min];
        countMinusArr[minusArrj_index[i] - min]--;
    }
    return ans;
}

// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Nhap du lieu dau vao
void inputData(vector<int> arr, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
}
