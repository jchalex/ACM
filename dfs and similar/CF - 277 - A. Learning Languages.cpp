#include <cstdio>
#include <cstring>

const int MAXN = 200 + 10;

int n;
int m;
bool G[MAXN][MAXN];
bool vis[MAXN];
int ret;

void Init()
{
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis));
}

void Read()
{
    int k;
    int v;

    ret = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k);
        if (k == 0)
        {
            ++ret;
        }
        for (int j = 0; j < k; ++j)
        {
            scanf("%d", &v);
            G[i][v + n] = G[v + n][i] = true;
        }
    }
}

void Dfs(int x)
{
    vis[x] = true;
    for (int i = 1; i <= n + m; ++i)
    {
        if (G[x][i] == true && vis[i] == false)
        {
            Dfs(i);
        }
    }
}

void Solve()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            Dfs(i);
            ++cnt;
        }
    }
    if (cnt - 1 > ret)
    {
        ret = cnt - 1;
    }
}

void Output()
{
    printf("%d\n", ret);
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        Init();
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

5 5
1 2
2 2 3
2 3 4
2 4 5
1 5
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
2 2
1 2
0
2 2
0
0

0
2
1

*/
