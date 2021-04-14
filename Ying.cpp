#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100;
const int Inf = 0x3f3f3f3f;

int tag = 1;
int read()
{
    int fl = 1, rt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            fl = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        rt = rt * 10 + ch - '0';
        ch = getchar();
    }
    if (ch == '\n')
        tag = 0;
    return fl * rt;
}

void Solve()
{
    int m;
    scanf("%d", &m); //行数

    int A[Maxn][Maxn];
    int col[Maxn];

    for (int i = 1; i <= m; i++)
    {
        int j = 0;
        tag = 1;
        //printf("ss");
        while (1)
        {
            A[i][++j] = read();
            if (!tag)
                break;
            // if (A[i][j] == -Inf)
            // {
            //     col[i] = j - 1;
            //     tag = 0;
            // }
        }
        col[i] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= col[i]; j++)
            printf("%d ", A[i][j]);
        puts("");
    }
}

int main()
{
    Solve();

    return 0;
}
/*
4
2 31
4 
2 4 5 1
2 4 2
*/