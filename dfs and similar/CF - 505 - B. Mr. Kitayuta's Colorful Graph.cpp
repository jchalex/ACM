#include <cstdio>
#include <cstring>

const int MAXN = 100 + 10;
const int MAXM = 200 + 10;

typedef struct _EDGE
{
	int to;
	int color;
	int nxt;
} EDGE;

int n;
int m;
int q;
int ecnt;
int hed[MAXN];
EDGE edge[MAXM];
bool vis[MAXN];

void Init()
{
	ecnt = 0;
	memset(hed, -1, sizeof(hed));
}

void AddEdge(int u, int v, int color)
{
	edge[ecnt].to = v;
	edge[ecnt].color = color;
	edge[ecnt].nxt = hed[u];
	hed[u] = ecnt++;
}

void Read()
{
	int u;
	int v;
	int color;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &color);
		AddEdge(u, v, color);
		AddEdge(v, u, color);
	}
}

bool Dfs(int x, int goal, int color, int fa)
{
	if (x == goal) return true;
	vis[x] = true;
	for (int e = hed[x]; e != -1; e = edge[e].nxt)
	{
		int v = edge[e].to;
		if (vis[v] == false && edge[e].color == color && v != fa)
		{
			if (Dfs(v, goal, edge[e].color, x) == true)
			{
				return true;
			}
		}
	}
	return false;
}

void Solve()
{
	int u;
	int v;
	int ret;

	scanf("%d", &q);
	while (q--)
	{
		ret = 0;
		scanf("%d%d", &u, &v);
		for (int i = 1; i <= m; ++i)
		{
			memset(vis, 0, sizeof(vis));
			if (Dfs(u, v, i, -1) == true)
			{
				++ret;
			}
		}
		printf("%d\n", ret);
	}
}

int main()
{
	// freopen("b.in", "r", stdin);
	while (scanf("%d%d", &n, &m) == 2)
	{
		Init();
		Read();
		Solve();
	}

	return 0;
}

/*
Ask for the number of color, not the paths!!!
*/