#include <bits/stdc++.h>

using namespace std;

class Matrix
{
private:
    int row;
    int **G;

public:
    Matrix() : G(nullptr) {}
    Matrix(int row) : row(row)
    {
        this->G = new int *[row + 1];
        for (int i = 0; i <= row; i++)
            this->G[i] = new int[row + 1];

        memset(this->G, 0, sizeof(this->G) * (row + 1) * (row + 1));
    }
    ~Matrix()
    {
        if (G != nullptr)
            delete[] G;
    }

public:
    int MaxSubmatrix();
};

int Matrix ::MaxSubmatrix()
{
}

void Solve()
{
}

int main()
{
    Solve();

    return 0;
}