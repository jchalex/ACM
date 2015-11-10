#include <cstdio>
#include <cstring>

const int MAXN = 2000 + 10;

typedef struct _EDGE
{
    int to;
    int nxt;
} EDGE;

int n;
int ret;
int vis[MAXN];
int hed[MAXN];
int ecnt;
EDGE edge[MAXN << 1];

void Init()
{
    memset(vis, -1, sizeof(vis));
    memset(hed, -1, sizeof(hed));
    ecnt = 0;
}

void AddEdge(int u, int v)
{
    edge[ecnt].to = v;
    edge[ecnt].nxt = hed[u];
    hed[u] = ecnt++;
}

void Read()
{
    int x, y;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        AddEdge(x, 1000 + y);
        AddEdge(1000 + y, x);
        vis[x] = 0;
        vis[1000 + y] = 0;
    }
}

void Dfs(int x)
{
    vis[x] = 1;
    for (int e = hed[x]; e != -1; e = edge[e].nxt)
    {
        if (vis[edge[e].to] == 0)
        {
            Dfs(edge[e].to);
        }
    }
}

void Solve()
{
    ret = 0;

    for (int i = 1; i <= 1000; ++i)
    {
        if (vis[i] == 0)
        {
            Dfs(i);
            ++ret;
        }
    }
}

void Output()
{
    printf("%d\n", ret - 1);
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        Init();
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

2
2 1
1 2
2
2 1
4 1

1
0

Point as edge.
*/
