#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using std::queue;
using std::max;

const int MAXN = 2000 + 10;
const int MAXM = (MAXN << 1);

typedef struct _EDGE
{
    int to;
    int nxt;
} EDGE;

int n;
int hed[MAXN];
EDGE edge[MAXM];
int ecnt;
int ret;

queue<int> qu;

void Init()
{
    while (!qu.empty()) qu.pop();
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
    int fa;

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &fa);
        if (fa == -1)
        {
            qu.push(i);
        }
        else
        {
            AddEdge(i, fa);
            AddEdge(fa, i);
        }
    }
}

int Dfs(int u, int fa)
{
    int ret = 0;
    bool leaf = true;

    for (int e = hed[u]; e != -1; e = edge[e].nxt)
    {
        int v = edge[e].to;

        if (v != fa)
        {
            leaf = false;
            ret = max(ret, Dfs(v, u));
        }
    }

    if (leaf) return 1;

    return ret + 1;
}

void Solve()
{
    ret = 0;
    while (!qu.empty())
    {
        int u = qu.front();

        qu.pop();
        ret = max(ret, Dfs(u, -1));
    }
}

void Output()
{
    printf("%d\n", ret);
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

5
-1
1
2
1
-1

3

*/
