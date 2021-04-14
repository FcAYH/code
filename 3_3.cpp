#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1001;
const int Inf = 0x3f3f3f3f;

int cnt = 0;
int n, ans = Inf;
int vis[Maxn];
int giv[Maxn];
int Ans[Maxn];
int cost[Maxn][Maxn];

void dfs(int per)
{
    if (per == n + 1)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += cost[i][giv[i]];

        puts("------------------");
        printf("%d: %d\n", ++cnt, sum);
        for (int i = 1; i <= n; i++)
            printf("%d ", giv[i]);
        puts("\n------------------");

        if (ans > sum)
        {
            ans = sum;
            for (int i = 1; i <= n; i++)
                Ans[i] = giv[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                giv[per] = i;
                dfs(per + 1);
                vis[i] = 0;
            }
        }
    }
}

void Solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    dfs(1);

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%d ", Ans[i]);
    puts("");
}

int main()
{
    Solve();

    return 0;
}

/*

6
2 3 1 4 8 2
5 2 4 1 9 4
6 5 3 4 12 5
2 6 3 1 7 11
11 29 42 10 4 5 2
4 124 51 52 1 24 6
*/