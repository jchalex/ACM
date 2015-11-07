#include <cstdio>

const int MAXN = 30000 + 10;

int n, t;
int a[MAXN];
bool ok;

void Read()
{
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", a + i);
    }
}

void Solve()
{
    int pos = 1;
    while (pos < t && pos < n)
    {
        pos += a[pos];
    }

    ok = (pos == t) ? true : false;
}

void Output()
{
    ok ? puts("YES") : puts("NO");
}

int main()
{
    while (scanf("%d%d", &n, &t) == 2)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

8 4
1 2 1 2 1 2 1
8 5
1 2 1 2 1 1 1

YES
NO

*/
