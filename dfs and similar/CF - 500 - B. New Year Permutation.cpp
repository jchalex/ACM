#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using std::vector;
using std::swap;

const int MAXN = 300 + 10;

int n;
int a[MAXN];
char G[MAXN][MAXN];
int groupId[MAXN];
int index[MAXN];
int ret[MAXN];

void Read()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", G[i]);
    }
}

void Dfs(int x, int id)
{
    groupId[x] = id;
    for (int i = 0; i < n; ++i)
    {
        if (G[x][i] == '1' && groupId[i] == -1)
        {
            Dfs(i, id);
        }
    }
}

void Solve()
{
    int cnt = 0;
    vector<int> vt[MAXN];

    memset(groupId, -1, sizeof(groupId));
    memset(index, 0, sizeof(index));
    for (int i = 0; i < n; ++i)
    {
        if (groupId[i] == -1)
        {
            Dfs(i, cnt);
            ++cnt;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        vt[groupId[i]].push_back(a[i]);
    }
    for (int i = 0; i < cnt; ++i)
    {
        sort(vt[i].begin(), vt[i].end());
    }
    for (int i = 0; i < n; ++i)
    {
        ret[i] = vt[groupId[i]][index[groupId[i]]++];
    }
}

void Output()
{
    printf("%d", ret[0]);
    for (int i = 1; i < n; ++i)
    {
        printf(" %d", ret[i]);
    }
    puts("");
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

7
5 2 4 3 6 7 1
0001001
0000000
0000010
1000001
0000000
0010000
1001000
5
4 2 1 5 3
00100
00011
10010
01101
01010

output
1 2 4 3 6 7 5
output
1 2 3 4 5

*/
