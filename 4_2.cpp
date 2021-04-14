#include <bits/stdc++.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    ~Point() {}
    Point(const Point &t)
    {
        this->x = t.x, this->y = t.y;
    }
    Point &operator=(const Point &t)
    {
        this->x = t.x, this->y = t.y;
    }

    void print()
    {
        printf("(%d, %d)\n", this->x, this->y);
    }
};

class Matrix
{
private:
    int row, col;
    int **G;

public:
    Matrix();
    ~Matrix() { delete[] G; }
    Matrix(const Matrix &t)
    {
        this->row = t.row, this->col = t.col;

        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 1; i <= this->row; i++)
                this->G[i] = new int[this->col + 1];
        }
        for (int i = 1; i <= t.row; i++)
            for (int j = 1; j <= t.col; j++)
                this->G[i][j] = t.G[i][j];
    }
    Matrix &operator=(const Matrix &t)
    {
        this->row = t.row, this->col = t.col;

        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 1; i <= this->row; i++)
                this->G[i] = new int[this->col + 1];
        }

        for (int i = 1; i <= t.row; i++)
            for (int j = 1; j <= t.col; j++)
                this->G[i][j] = t.G[i][j];
    }

public:
    void set_Element();
    void sort();                    // sort the Matrix form upper_left to button_right
    Point Bruteforce_search(int x); //force_search x from the Matrix
    Point Binary_search1(int x);    //binary_search x from the Matrix,row by row
    Point Binary_search2(int x);    //binary_search x from the Matrix, one -> four
};

void Matrix::set_Element()
{
    printf("Please input the row and column of the Matrix:\n");

    scanf("%d%d", &this->row, &this->col);

    if (this->G != nullptr)
        delete[] G;

    this->G = new int *[this->row + 1];
    for (int i = 1; i <= this->row; i++)
        this->G[row] = new int[this->col + 1];

    printf("Please input the element of the Matrix");
    for (int i = 1; i <= this->row; i++)
        for (int j = 1; j <= this->col; j++)
            scanf("%d", &this->G[i][j]);
}
void Matrix::sort()
{
    //TODO: Matrix sort
}
Point Matrix::Bruteforce_search(int x)
{
    for (int i = 1; i <= this->row; i++)
    {
        for (int j = 1; j <= this->col; i++)
        {
            if (this->G[i][j] == x)
            {
                Point reP(i, j);
                return reP;
            }
        }
    }
}
Point Matrix::Binary_search1(int x)
{
    //because the Matrix has been sorted
    //row by row

    for (int i = 1; i <= this->row; i++)
    {
        int l = 1, r = this->col;

        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (this->G[i][mid] == x)
            {
                Point reP(i, mid);
                return reP;
            }

            if (this->G[i][mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
}

Point Matrix::Binary_search2(int x)
{
    //because the Matrix has been sorted
}

void Solve()
{
    Matrix M;
    M.set_Element();

    int toFind;
    scanf("%d", &toFind);

    Point Ans;
    Ans = M.Bruteforce_search(toFind);
    printf("After Bruteforce_search, We find the number at ");
    Ans.print();

    Ans = M.Binary_search1(toFind);
    printf("After Binary_search row by row, We find the number at ");
    Ans.print();

    Ans = M.Binary_search2(toFind);
    printf("After Binary_search one to four, We find the number at ");
    Ans.print();
}

int main()
{
    Solve();

    return 0;
}