#include <cstdio>
#include <cstring>

const int MAXS = 362880 + 10;
const int MAXH = 1000003;

typedef int State[9];

char a[9][2];
char dir[MAXS];
int goalId;
int fa[MAXS];
State start, goal;
State st[MAXS];
int dx[] = {-1, 1,  0, 0};
int dy[] = { 0, 0, -1, 1};
int hed[MAXH], nxt[MAXS];

void Init()
{
    for (int i = 0; i < 9; ++i)
    {
        if (a[i][0] == 'x')
        {
            start[i] = 0;
        }
        else
        {
            start[i] = a[i][0] - '0';
        }

        goal[i] = i + 1;
    }
    goal[8] = 0;

    fa[1] = -1;

    memset(hed, -1, sizeof(hed));
}

int Hash(State s)
{
    int x = 0;

    for (int i = 0; i < 9; ++i)
    {
        x = x * 10 + s[i];
    }

    return x % MAXH;
}

bool Insert(int id)
{
    int ret = true;
    int h = Hash(st[id]);

    for (int e = hed[h]; e != -1; e = nxt[e])
    {
        if (memcmp(st[id], st[e], sizeof(st[e])) == 0)
        {
            ret = false;
            break;
        }
    }

    if (ret)
    {
        nxt[id] = hed[h];
        hed[h] = id;
    }

    return ret;
}

char GetDir(int x)
{
    char ret = '\0';

    switch (x)
    {
    case 0:
        ret = 'u';
        break;
    case 1:
        ret = 'd';
        break;
    case 2:
        ret = 'l';
        break;
    case 3:
        ret = 'r';
        break;
    }

    return ret;
}

int Bfs()
{
    int frt = 1;
    int rear = 2;

    memcpy(st[1], start, sizeof(start));
    while (frt < rear)
    {
        int z;
        State& s = st[frt];

        if (memcmp(s, goal, sizeof(goal)) == 0) return frt;

        for (z = 0; z < 9 && s[z] != 0; ++z);
        int x = z / 3;
        int y = z % 3;
        for (int i = 0; i < 4; ++i)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            int newz = newx * 3 + newy;

            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                State& t = st[rear];
                memcpy(t, s, sizeof(s));
                t[z] = t[newz];
                t[newz] = 0;

                if (Insert(rear))
                {
                    fa[rear] = frt;
                    dir[rear] = GetDir(i);
                    ++rear;
                }
            }
        }
        ++frt;
    }

    return 0;
}

void Solve()
{
    goalId = Bfs();
}

void DfsOutput(int id)
{
    if (fa[id] == -1) return;
    DfsOutput(fa[id]);
    putchar(dir[id]);
}

void Output()
{
    if (goalId == 0)
    {
        puts("unsolvable");
    }
    else
    {
        DfsOutput(goalId);
        puts("");
    }
}

int main()
{
    while (scanf("%s%s%s%s%s%s%s%s%s", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]) == 9)
    {
        Init();
        Solve();
        Output();
    }

    return 0;
}

/*

Sample Input
2  3  4  1  5  x  7  6  8

Sample Output
ullddrurdllurdruldr

*/
