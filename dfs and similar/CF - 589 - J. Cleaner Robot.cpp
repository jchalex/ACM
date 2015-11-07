#include <cstdio>
#include <cstring>

const int MAXN = 10 + 5;

int w;
int h;
int ret;
int startX;
int startY;
int startD;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool backVis[MAXN][MAXN][4];
int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};

int getDir(char d)
{
    if (d == 'U') return 0;
    if (d == 'R') return 1;
    if (d == 'D') return 2;
    if (d == 'L') return 3;
    return 0;
}

void Read()
{
    for (int i = 0; i < w; ++i)
    {
        getchar();
        for (int j = 0; j < h; ++j)
        {
            G[i][j] = getchar();
            if (G[i][j] != '.' && G[i][j] != '*')
            {
                startX = i;
                startY = j;
                startD = getDir(G[i][j]);
            }
        }
    }
}

void Dfs(int x, int y, int d)
{
    if (!vis[x][y])
    {
        vis[x][y] = true;
        ++ret;
    }
    if (backVis[x][y][d]) return;
    backVis[x][y][d] = true;

    int newx = x + dx[d];
    int newy = y + dy[d];

    if (newx >= 0 && newx < w && newy >= 0 && newy < h)
    {
        if (G[newx][newy] == '*')
        {
            Dfs(x, y, (d + 1) % 4);
        }
        else
        {
            Dfs(newx, newy, d);
        }
    }
    else
    {
        Dfs(x, y, (d + 1) % 4);
    }
}

void Solve()
{
    ret = 0;
    memset(vis, 0, sizeof(vis));
    memset(backVis, 0, sizeof(backVis));
    Dfs(startX, startY, startD);
}

void Output()
{
    printf("%d\n", ret);
}

int main()
{
    while (scanf("%d%d", &w, &h) == 2)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

input
2 3
U..
.*.
4 4
R...
.**.
.**.
....
3 4
***D
..*.
*...

4
12
6

*/
