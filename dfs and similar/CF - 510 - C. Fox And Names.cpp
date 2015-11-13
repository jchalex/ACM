#include <cstdio>
#include <cstring>

const int MAXN = 100 + 10;
const int MAXA = 26;

typedef struct _EDGE
{
    int to;
    int nxt;
} EDGE;

int n;
int ecnt;
int hed[MAXA];
EDGE edge[MAXN];
int ret[MAXA];
int cnt;
int vis[MAXA];
bool ok;

void Init()
{
    ok = true;
    cnt = 26;
    ecnt = 0;
    memset(hed, -1, sizeof(hed));
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
    int id = 0;
    char s[2][MAXN];

    scanf("%s", s[id]);
    for (int i = 1; i < n; ++i)
    {
        id ^= 1;
        scanf("%s", s[id]);

        int len1 = strlen(s[id ^ 1]);
        int len2 = strlen(s[id]);
        bool samePre = true;

        for (int j = 0; j < len1 && j < len2; ++j)
        {
            if (s[id ^ 1][j] != s[id][j])
            {
                AddEdge(s[id ^ 1][j] - 'a', s[id][j] - 'a');
                samePre = false;
                break;
            }
        }
        if (samePre)
        {
            if (len1 > len2)
            {
                ok = false;
            }
        }
    }
}

bool Dfs(int x)
{
    vis[x] = 1;
    for (int e = hed[x]; e != -1; e = edge[e].nxt)
    {
        int v = edge[e].to;

        if (vis[v] == 1)
        {
            return false;
        }
        if (vis[v] == 0 && Dfs(v) == false)
        {
            return false;
        }
    }
    ret[--cnt] = x;
    vis[x] = -1;

    return true;
}

bool TopoSort()
{
    bool ret = true;

    for (int i = 0; i < MAXA; ++i)
    {
        if (vis[i] == 0)
        {
            ret = Dfs(i);
            if (ret == false) break;
        }
    }

    return ret;
}

void Solve()
{
    if (ok == false || TopoSort() == false)
    {
        puts("Impossible");
    }
    else
    {
        for (int i = 0; i < MAXA; ++i)
        {
            putchar(ret[i] + 'a');
        }
        puts("");
    }
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        Init();
        Read();
        Solve();
    }

    return 0;
}

/*

3
rivest
shamir
adleman
10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooooooo
subscriber
rowdark
tankengineer
10
petr
egor
endagorion
feferivan
ilovetanyaromanova
kostka
dmitriyh
maratsnowbear
bredorjaguarturnik
cgyforever
7
car
care
careful
carefully
becarefuldontforgetsomething
otherwiseyouwillbehacked
goodluck

bcdefghijklmnopqrsatuvwxyz
Impossible
aghjlnopefikdmbcqrstuvwxyz
acbdefhijklmnogpqrstuvwxyz

*/
