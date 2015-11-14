#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::lower_bound;

const int MAXN = 20 + 5;
const int MAXM = 420 + 10;
const int MAXP = 30 + 5;

typedef struct _EDGE
{
	int to;
	int w;
	int nxt;
} EDGE;

int T;
int N;
int M;
int P[MAXN];
int hed[MAXN];
int ecnt;
EDGE edge[MAXM];
int actualPrice[MAXN];
int ret;

void Init()
{
	ecnt = 0;
	memset(hed, -1, sizeof(hed));
}

void AddEdge(int u, int v, int w)
{
	edge[ecnt].to = v;
	edge[ecnt].w = w;
	edge[ecnt].nxt = hed[u];
	hed[u] = ecnt++;
}

void Read()
{
	int q;
	int p;
	int N1;
	int N2;
	int R;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &q, &p);
		P[q] = p;
	}
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d%d%d", &N1, &N2, &R);
		AddEdge(N1, N2, R);
	}
}

void Dfs(int x)
{
	for (int e = hed[x]; e != -1; e = edge[e].nxt)
	{
		int v = edge[e].to;
		int w = edge[e].w;

		if (actualPrice[x] + w < actualPrice[v])
		{
			actualPrice[v] = actualPrice[x] + w;
			Dfs(v);
		}
	}
}

void Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		actualPrice[i] = P[i] - 1;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			if (P[i] == P[j])
			{
				AddEdge(i, j, 0);
				AddEdge(j, i, 0);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		Dfs(i);
	}

	ret = 0;
	for (int i = 1; i <= N; ++i)
	{
		bool ok = false;

		for (int j = 1; j <= N; ++j)
		{
			if (i == j) continue;
			for (int k = 1; k <= N; ++k)
			{
				if (i == k || j == k) continue;
				if (actualPrice[i] == actualPrice[j] + actualPrice[k])
				{
					++ret;
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
	}
}

void Output()
{
	for (int i = 1; i <= N; ++i)
	{
		printf("%d %d\n", i, actualPrice[i]);
	}
	printf("%d\n", ret);
}

int main()
{
	// freopen("D.in", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		Init();
		Read();
		Solve();
		Output();
	}

	return 0;
}