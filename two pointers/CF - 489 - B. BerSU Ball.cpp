#include <cstdio>
#include <algorithm>
#include <cmath>

using std::sort;

const int MAXN = 100 + 10;

int n;
int m;
int boy[MAXN];
int girl[MAXN];
int ret;

void Read()
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", boy + i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", girl + i);
    }
}

void Solve()
{
    ret = 0;
    sort(boy, boy + n);
    sort(girl, girl + m);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (abs(boy[i] - girl[j]) <= 1)
        {
            ++ret;
            ++i;
            ++j;
        }
        else
        {
            if (boy[i] < girl[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
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

4
1 4 6 2
5
5 1 5 7 9
4
1 2 3 4
4
10 11 12 13
5
1 1 1 1 1
3
1 2 3

3
0
2

*/
