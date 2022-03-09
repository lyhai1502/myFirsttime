#pragma once
#include "SinhVien.h"
class List
{
private:
    int amountOfSinhVien;
    SinhVien list[1000];

public:
    void inputList();
    void outputList();
    void sortScores();
};

