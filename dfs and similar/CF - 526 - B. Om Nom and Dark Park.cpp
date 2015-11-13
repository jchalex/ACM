#include <cstdio>
#include <algorithm>
#include <cstring>

using std::max;
using std::min;

const int MAXN = 2048;

int n;
int nodeCnt;
int a[MAXN];
int ret;
int maxLight;
int light[MAXN];
int need[MAXN];

void Read()
{
    nodeCnt = (1 << (n + 1)) - 1;
    for (int i = 2; i <= nodeCnt; ++i)
    {
        scanf("%d", a + i);
    }
}

void DfsLight(int x)
{
    if (x > nodeCnt) return;
    light[x] = light[x >> 1] + a[x];
    DfsLight(x << 1);
    DfsLight((x << 1) + 1);
}

void GetMaxLight()
{
    light[0] = 0;
    DfsLight(1);
    maxLight = 0;
    for (int i = (1 << n); i <= nodeCnt; ++i)
    {
        maxLight = max(maxLight, light[i]);
    }
}

int Dfs(int x)
{
    if (need[x] != -1) return need[x];
    return (need[x] = min(Dfs(x << 1), Dfs((x << 1) + 1)));
}

void Solve()
{
    GetMaxLight();
    memset(need, -1, sizeof(need));
    for (int i = (1 << n); i <= nodeCnt; ++i)
    {
        need[i] = maxLight - light[i];
    }
    Dfs(1);
    ret = 0;
    for (int i = 2; i <= nodeCnt; ++i)
    {
        ret += need[i] - need[i >> 1];
    }
}

void Output()
{
    printf("%d\n", ret);
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

2
1 2 3 4 5 6

*/
