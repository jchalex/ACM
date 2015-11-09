#include <cstdio>

const int MAXN = 500 + 10;

int n;
int m;
int k;
int sum;
int cur;
int dx[] = {-1, 1,  0, 0};
int dy[] = { 0, 0, -1, 1};
char G[MAXN][MAXN];

void Read()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", G[i]);
    }
}

void Dfs(int x, int y)
{
    if (cur >= sum - k) return;
    G[x][y] = 'C';
    ++cur;
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx >= 0 && newx < n && newy >= 0 && newy < m && G[newx][newy] == '.')
        {
            Dfs(newx, newy);
        }
    }
}

void Solve()
{
    bool ok = false;

    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j] == '.')
            {
                ++sum;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j] == '.')
            {
                cur = 0;
                Dfs(i, j);
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j] == '.')
            {
                G[i][j] = 'X';
            }
            else if (G[i][j] == 'C')
            {
                G[i][j] = '.';
            }
        }
    }
}

void Output()
{
    for (int i = 0; i < n; ++i)
    {
        puts(G[i]);
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &k) == 3)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

3 4 2
#..#
..#.
#...
5 4 5
#...
#.#.
.#..
...#
.#.#

#.X#
X.#.
#...

#XXX
#X#.
X#..
...#
.#.#

To delete k cells, consider maintaining sum - k cells.
cur can not use as a para in function.
*/
