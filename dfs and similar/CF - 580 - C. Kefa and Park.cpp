#include <cstdio>
#include <cstring>

const int MAXN = 100000 + 10;

typedef struct _Edge
{
    int to;
    int nxt;
} Edge;

int n, m;
int ret;
int cat[MAXN];
int hed[MAXN];
int ecnt;
Edge edge[MAXN << 1];

void Init()
{
    ret = 0;
    ecnt = 0;
    memset(hed, -1, sizeof(hed));
}

void AddEdge(int u, int v)
{
    edge[ecnt].to = v;
    edge[ecnt].nxt = hed[u];
    hed[u] = ecnt++;
}

void Read()
{
    int u, v;

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", cat + i);
    }
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
}

void Dfs(int u, int fa, int cur)
{
    if (cur > m) return;

    bool isLeaf = true;

    for (int e = hed[u]; e != -1; e = edge[e].nxt)
    {
        int v = edge[e].to;
        if (v != fa)
        {
            if (cat[v])
            {
                Dfs(v, u, cur + 1);
            }
            else
            {
                Dfs(v, u, 0);
            }
            isLeaf = false;
        }
    }
    if (isLeaf)
    {
        ++ret;
    }
}

void Solve()
{
    if (cat[1])
    {
        Dfs(1, -1, 1);
    }
    else
    {
        Dfs(1, -1, 0);
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
4 1
1 1 0 0
1 2
1 3
1 4

7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7

2
2

*/
