#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int MAXN = 4000 + 10;
const int INF = 0x3f3f3f3f;

typedef struct _EDGE
{
    int frt;
    int to;

    _EDGE() {}
} EDGE;

int n;
int m;
int ret;
int degree[MAXN];
bool G[MAXN][MAXN];
EDGE edge[MAXN];

void Init()
{
    memset(G, 0, sizeof(G));
    memset(degree, 0, sizeof(degree));
}

void Read()
{
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &edge[i].frt, &edge[i].to);
        ++degree[edge[i].frt];
        ++degree[edge[i].to];
        G[edge[i].frt][edge[i].to] = true;
        G[edge[i].to][edge[i].frt] = true;
    }
}

void Solve()
{
    ret = INF;
    for (int i = 0; i < n; ++i)
    {
        for (int e = 0; e < m; ++e)
        {
            if (G[i][edge[e].frt] && G[i][edge[e].to])
            {
                ret = min(ret, degree[i] + degree[edge[e].frt] + degree[edge[e].to] - 6);
            }
        }
    }
    if (ret == INF)
    {
        ret = -1;
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

5 6
1 2
1 3
2 3
2 4
3 4
4 5
7 4
2 1
3 6
5 1
1 7

2
-1

*/
