#include <cstdio>
#include <cstring>

const int MAXN = 300 + 10;
const int dx[] = {0, 1,  0, -1};
const int dy[] = {1, 0, -1,  0};

int n;
int m;
int k;
int curX;
int curY;
int dir;
bool vis[MAXN][MAXN];

void Dfs(int x, int y, int cnt)
{
    if (cnt == 0)
    {
        curX = x;
        curY = y;
        return;
    }

    printf(" %d %d", x, y);
    vis[x][y] = true;

    int newx = x + dx[dir];
    int newy = y + dy[dir];

    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == false)
    {
        Dfs(newx, newy, cnt - 1);
    }
    else
    {
        dir = (dir + 1) % 4;
        Dfs(x + dx[dir], y + dy[dir], cnt - 1);
    }
}

void SetCur()
{
    if (vis[curX][curY] == false) return;

    int newx = curX + dx[dir];
    int newy = curY + dy[dir];

    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == false)
    {
        curX = newx;
        curY = newy;
    }
    else
    {
        dir = (dir + 1) % 4;
        curX = curX + dx[dir];
        curY = curY + dy[dir];
    }
}

void Solve()
{
    curX = 1;
    curY = 1;
    dir = 0;

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < k; ++i)
    {
        printf("2");
        SetCur();
        Dfs(curX, curY, 2);
        puts("");
    }

    int cnt = n * m - 2 * (k - 1);

    printf("%d", cnt);
    SetCur();
    Dfs(curX, curY, cnt);
    puts("");
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &k) == 3)
    {
        Solve();
    }

    return 0;
}

/*

3 3 3
output
3 1 1 1 2 1 3
3 2 1 2 2 2 3
3 3 1 3 2 3 3
input
2 3 1
output
6 1 1 1 2 1 3 2 3 2 2 2 1

*/
