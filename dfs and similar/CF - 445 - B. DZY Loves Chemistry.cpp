#include <cstdio>
#include <cstring>

const int MAXN = 50 + 5;
const int MAXM = 1250 + 10;

typedef struct _EDGE
{
    int to;
    int nxt;
} EDGE;

int n, m;
int cnt;
int ecnt;
int hed[MAXN];
EDGE edge[MAXM << 1];
long long ret;
int vis[MAXN];

void Init()
{
    ret = 0;
    ecnt = 0;
    memset(hed, -1, sizeof(hed));
    memset(vis, 0, sizeof(vis));
}

void AddEdge(int u, int v)
{
    edge[ecnt].to = v;
    edge[ecnt].nxt = hed[u];
    hed[u] = ecnt++;
}

void Read()
{
    int u;
    int v;

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
}

void Dfs(int x, int fa)
{
    vis[x] = 1;
    ++cnt;

    for (int e = hed[x]; e != -1; e = edge[e].nxt)
    {
        int v = edge[e].to;

        if (v != fa && vis[v] == 0)
        {
            Dfs(v, x);
        }
    }
}

void Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 0)
        {
            cnt = 0;
            Dfs(i, -1);
            ret += cnt - 1;
        }
    }
    ret = (1LL << ret);
}

void Output()
{
    printf("%I64d\n", ret);
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

40 40
28 33
15 21
12 29
14 31
2 26
3 12
25 34
6 30
6 25
5 28
9 17
23 29
30 36
3 21
35 37
7 25
29 39
15 19
12 35
24 34
15 25
19 33
26 31
7 29
1 40
11 27
6 9
6 27
36 39
10 14
6 16
23 25
2 38
3 24
30 31
29 30
4 12
11 13
14 40
22 39


3 2
1 2
2 3

34359738368
4

1LL not 1L
*/
