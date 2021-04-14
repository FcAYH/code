#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1001;
const int Inf = 0x3f3f3f3f;

int n, ans = Inf;
int vis[Maxn];
int giv[Maxn];
int Ans[Maxn];
int cost[Maxn][Maxn];

void dfs(int per, int nowv)
{
    if (per == n + 1)
    {
        if (ans > nowv)
        {
            ans = nowv;
            for (int i = 1; i <= n; i++)
                Ans[i] = giv[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && nowv + cost[per][i] < ans)
            {
                vis[i] = 1;
                giv[per] = i;
                dfs(per + 1, nowv + cost[per][i]);
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

    dfs(1, 0);

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

4
2 3 1 4
5 2 4 1
6 5 3 4
2 6 3 1

*/