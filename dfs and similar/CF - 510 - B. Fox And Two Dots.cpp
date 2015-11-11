#include <cstdio>
#include <cstring>

const int MAXN = 50 + 5;
const int dx[] = {-1, 1,  0, 0};
const int dy[] = { 0, 0, -1, 1};

int n;
int m;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool ok;

void Read()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", G[i]);
    }
}

void Dfs(int x, int y, char mark, int fa)
{
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx >= 0 && newx < n && newy >= 0 && newy < m && G[newx][newy] == mark && newx * n + newy != fa)
        {
            if (vis[newx][newy])
            {
                ok = true;
                return;
            }
            vis[newx][newy] = true;
            Dfs(newx, newy, mark, x * n + y);
        }
    }

}

void Solve()
{
    ok = false;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vis[i][j] == false)
            {
                vis[i][j] = true;
                Dfs(i, j, G[i][j], -1);
            }
            if (ok) break;
        }
        if (ok) break;
    }
}

void Output()
{
    ok ? puts("Yes") : puts("No");
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

3 4
AAAA
ABCA
AAAA
3 4
AAAA
ABCA
AADA
4 4
YYYR
BYBY
BBBY
BBBY
7 6
AAAAAB
ABBBAB
ABAAAB
ABABBB
ABAAAB
ABBBAB
AAAAAB
2 13
ABCDEFGHIJKLM
NOPQRSTUVWXYZ

Yes
No
Yes
Yes
NO

*/
