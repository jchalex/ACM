#include <cstdio>
#include <queue>

using std::queue;

const int MAXF = 32659200 + 1;

int n;
int fightCnt;
int winner;
queue<int> quA;
queue<int> quB;

void Init()
{
    while(!quA.empty()) quA.pop();
    while(!quB.empty()) quB.pop();
}

void Read()
{
    int cnt;
    int num;

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i)
    {
        scanf("%d", &num);
        quA.push(num);
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i)
    {
        scanf("%d", &num);
        quB.push(num);
    }
}

void Solve()
{
    fightCnt = 0;

    for (int i = 0; i < MAXF; ++i)
    {
        if (quA.empty())
        {
            winner = 2;
            break;
        }
        if (quB.empty())
        {
            winner = 1;
            break;
        }

        int a = quA.front();
        int b = quB.front();

        quA.pop();
        quB.pop();
        if (a > b)
        {
            quA.push(b);
            quA.push(a);
        }
        else
        {
            quB.push(a);
            quB.push(b);
        }
        ++fightCnt;
    }

    if (fightCnt == MAXF)
    {
        fightCnt = -1;
    }
}

void Output()
{
    if (fightCnt == -1)
    {
        puts("-1");
    }
    else
    {
        printf("%d %d\n", fightCnt, winner);
    }
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        Init();
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

4
2 1 3
2 4 2
3
1 2
2 1 3

6 2
-1

*/
