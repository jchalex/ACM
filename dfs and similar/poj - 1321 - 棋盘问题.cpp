#include <cstdio>
#include <cstring>

const int MAXN = 8 + 10;

int n;
int k;
int C;
char G[MAXN][MAXN];
bool vis[MAXN];

void Dfs(int curRow, int curCnt)
{
	if (curCnt == k)
	{
		++C;
		return;
	}
	if (curRow == n) return;

	for (int i = 0; i < n; ++i)
	{
		if (G[curRow][i] == '#' && vis[i] == false)
		{
			vis[i] = true;
			Dfs(curRow + 1, curCnt + 1);
			vis[i] = false;
		}
	}
	Dfs(curRow + 1, curCnt);
}

void Read()
{
	for (int i = 0; i < n; ++i)
	{
		getchar();
		for (int j = 0; j < n; ++j)
		{
			G[i][j] = getchar();
		}
	}
}

void Solve()
{
	C = 0;
	memset(vis, 0, sizeof(vis));
	Dfs(0, 0);
}

void Output()
{
	printf("%d\n", C);
}

int main()
{
	// freopen("poj_1321.in", "r", stdin);
	while (scanf("%d%d", &n, &k) == 2)
	{
		if (n == -1 && k == -1) break;
		Read();
		Solve();
		Output();
	}
	return 0;
}