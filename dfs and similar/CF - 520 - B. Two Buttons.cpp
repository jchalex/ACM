#include <cstdio>

int n, m;
int ret;

void Init()
{
    ret = 0;
}

void Dfs(int cur)
{
    if (cur <= n)
    {
        ret += n - cur;
        return;
    }

    if (cur & 1)
    {
        ret += 2;
        Dfs((cur + 1) >> 1);
    }
    else
    {
        ++ret;
        Dfs(cur >> 1);
    }
}

void Output()
{
    printf("%d\n", ret);
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        Init();
        Dfs(m);
        Output();
    }

    return 0;
}

/*

4 6
10 1

2
9

*/
