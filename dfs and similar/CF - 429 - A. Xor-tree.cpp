#include <cstdio>
#include <cstring>

const int MAXN = 100000 + 10;

typedef struct _EDGE
{
    int to;
    int nxt;
} EDGE;

int n;
int ecnt;
int hed[MAXN];
EDGE edge[MAXN << 1];
int cur[MAXN];
int goal[MAXN];
int vis[MAXN];
int minCnt;
int ret[MAXN];

void Init()
{
    memset(hed, -1, sizeof(hed));
    ecnt = 0;
    minCnt = 0;
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

    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    for (int i = 1; i <= n; ++i)
    {
    	scanf("%d", cur + i);
    }
    for (int i = 1; i <= n; ++i)
    {
    	scanf("%d", goal + i);
    }

}

void Dfs(int x, int fa)
{
	if (vis[x] == 1)
	{
		cur[x] ^= 1;
	}

	if (cur[x] != goal[x])
	{
		vis[x] ^= 1;
		ret[minCnt++] = x;
	}

	if (vis[x] == 1)
	{
		for (int e = hed[x]; e != -1; e = edge[e].nxt)
		{
			int v = edge[e].to;

			if (v != fa)
			{
				for (int i = hed[v]; i != -1; i = edge[i].nxt)
				{
					int vv = edge[i].to;

					if (vv != x)
					{
						vis[vv] ^= 1;
					}
				}
			}
		}		
	}

	for (int e = hed[x]; e != -1; e = edge[e].nxt)
	{
		int v = edge[e].to;

		if (v != fa)
		{
			Dfs(v, x);
		}
	}
}

void Solve()
{
	Dfs(1, -1);
}

void Output()
{
	printf("%d\n", minCnt);
	for (int i = 0; i < minCnt; ++i)
	{
		printf("%d\n", ret[i]);
	}
}

int main()
{
	// freopen("B.in", "r", stdin);
    while (scanf("%d", &n) == 1)
    {
        Init();
        Read();
        Solve();
        Output();
    }

    return 0;
}
