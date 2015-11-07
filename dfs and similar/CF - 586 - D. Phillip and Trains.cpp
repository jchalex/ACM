#include <cstdio>

const int MAXN = 100 + 10;

int n, k;
int startR;
bool ret;
char s[3][MAXN];

void Read()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 3; ++i)
    {
        scanf("%s", s[i]);
        if (s[i][0] == 's')
        {
            startR = i;
        }
    }
}

bool Dfs(int x, int y)
{
    if (y >= n - 2) return true;

    if (s[x][y + 1] != '.') return false;
    if (y + 3 >= n) return true;

    bool ok = false;
    if (s[x][y + 3] == '.')
    {
        ok |= Dfs(x, y + 3);
        s[x][y + 3] = '#';
    }
    if (!ok && x - 1 >= 0 && s[x - 1][y + 1] == '.' && s[x - 1][y + 3] == '.')
    {
        ok |= Dfs(x - 1, y + 3);
        s[x - 1][y + 3] = '#';
    }
    if (!ok && x + 1 < 3 && s[x + 1][y + 1] == '.' && s[x + 1][y + 3] == '.')
    {
        ok |= Dfs(x + 1, y + 3);
    }

    return ok;
}

void Solve()
{
    ret = Dfs(startR, 0);
}

void Output()
{
    ret ? puts("YES") : puts("NO");
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t--)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

4
16 4
...AAAAA........
s.BBB......CCCCC
........DDDDD...
16 4
...AAAAA........
s.BBB....CCCCC..
.......DDDDD....
10 4
s.ZZ......
.....AAABB
.YYYYYY...
10 4
s.ZZ......
....AAAABB
.YYYYYY...

YES
NO
YES
NO

*/
