#include <bits/stdc++.h>

using namespace std;

class Matrix
{
private:
    const int Inf = 0x3f3f3f3f;
    int row;
    int **G;

public:
    Matrix() : G(nullptr) {}
    Matrix(int row) : row(row)
    {
        this->G = new int *[row + 1];
        for (int i = 0; i <= row; i++)
            this->G[i] = new int[row + 1];

        for (int i = 0; i <= row; i++)
            this->G[i][0] = 0, this->G[0][i] = 0;
    }
    ~Matrix()
    {
        if (G != nullptr)
            delete[] G;
    }

private:
    int MaxSubsequence(const int *temp);

public:
    int GetRow();
    void SetElement();
    int MaxSubmatrix();
};

int Matrix::MaxSubsequence(const int *nums)
{
    int Ans = -Inf, temp = -Inf;
    for (int i = 1; i <= row; i++)
    {
        temp = max(nums[i], nums[i] + temp);
        Ans = max(Ans, temp);
    }

    return Ans;
}

inline int Matrix::GetRow()
{
    return this->row;
}
void Matrix::SetElement()
{
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= row; j++)
            scanf("%d", &this->G[i][j]);
}
int Matrix::MaxSubmatrix()
{
    int **total = this->G;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= row; j++)
            total[i][j] += total[i - 1][j];

    int Ans = -Inf;
    for (int i = 1; i <= row; i++)
    {
        for (int j = i; j <= row; j++)
        {
            int *result = new int[row + 1];
            for (int f = 1; f <= row; f++)
                result[f] = (i == 1) ? total[j][f] : total[j][f] - total[i - 1][f];

            int Max = MaxSubsequence(result);

            Ans = max(Max, Ans);
        }
    }

    return Ans;
}

void Solve()
{
    int n;
    scanf("%d", &n);
    Matrix *matrix = new Matrix(n);

    matrix->SetElement();
    printf("%d\n", matrix->MaxSubmatrix());

    delete matrix;
}

int main()
{
    Solve();

    return 0;
}

/*
3
3 2 -2 
-1 3 4
3 -1 2

6
2 -3 4 1 -7 -8
5 6 -3 -10 3 1
-2 -4 1 1 4 6 8
-10 2 0 -5 -9 3
6 8 -3 -7 9 1
2 2 4 -7 -5 -4
*/