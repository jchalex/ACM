#include <cstdio>
#include <algorithm>

const int MAXN = 10000 + 10;

int N, Q;
int a[MAXN];
int kase;

void Read()
{
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &a[i]);
    }
}

void Solve()
{
    int x;

    printf("CASE# %d:\n", ++kase);
    std::sort(a + 1, a + 1 + N);
    while (Q--)
    {
        scanf("%d", &x);
        int id = std::lower_bound(a + 1, a + 1 + N, x) - a;
        if (id <= N && a[id] == x)
        {
            printf("%d found at %d\n", x, id);
        }
        else
        {
            printf("%d not found\n", x);
        }
    }
}

int main()
{
    kase = 0;
    while (scanf("%d%d", &N, &Q) == 2)
    {
        if (!N && !Q) break;
        Read();
        Solve();
    }

    return 0;
}

/*

Sample Input
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0

Sample Output
CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3

*/
