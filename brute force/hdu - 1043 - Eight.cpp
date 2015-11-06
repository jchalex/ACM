#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;

const int MAXH = 362880 + 10;
const int MAXW = 9;

typedef struct _NODE
{
    int id;
    int st[MAXW];

    _NODE() {}
    _NODE(const int _id, const int* _st) : id(_id)
    {
        for (int i = 0; i < MAXW; ++i)
        {
            st[i] = _st[i];
        }
    }
} NODE;

char ch[MAXW];
int dx[] = {-1, 1,  0, 0};
int dy[] = { 0, 0, -1, 1};
int fac[MAXW];
int start[MAXW];
bool vis[MAXH];
string G[MAXH];

int Cantor(const int* arr)
{
    int ret = 0;

    for (int i = 0; i < 9; ++i)
    {
        int cnt = 0;
        for (int j = i + 1; j < 9; ++j)
        {
            if (arr[j] < arr[i])
            {
                ++cnt;
            }
        }
        ret += cnt * fac[8 - i];
    }

    return ret;
}

void Init()
{
    fac[0] = 1;
    for (int i = 1; i < 9; ++i)
    {
        fac[i] = fac[i - 1] * i;
    }
    memset(vis, 0, sizeof(vis));
}

void Bfs()
{
    queue<NODE> qu;
    int arrGoal[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int goalId = Cantor(arrGoal);
    NODE v;

    G[goalId] = "";
    qu.push(NODE(goalId, arrGoal));
    while (!qu.empty())
    {
        NODE& u = qu.front();
        int z = 0;
        while (u.st[z] != 0) ++z;
        int x = z / 3;
        int y = z % 3;

        for (int i = 0; i < 4; ++i)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            int newz = newx * 3 + newy;

            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                memcpy(v.st, u.st, sizeof(u.st));
                v.st[z] = v.st[newz];
                v.st[newz] = 0;
                v.id = Cantor(v.st);
                if (!vis[v.id])
                {
                    switch (i)
                    {
                    case 0: G[v.id] = "d" + G[u.id]; break;
                    case 1: G[v.id] = "u" + G[u.id]; break;
                    case 2: G[v.id] = "r" + G[u.id]; break;
                    case 3: G[v.id] = "l" + G[u.id]; break;
                    }
                    vis[v.id] = true;
                    qu.push(v);
                }
            }
        }
        qu.pop();
    }
}

void Solve()
{
    for (int i = 0; i < 9; ++i)
    {
        if (ch[i] == 'x')
        {
            start[i] = 0;
        }
        else
        {
            start[i] = ch[i] - '0';
        }
    }
}

void Output()
{
    int id = Cantor(start);

    if (vis[id] == 0)
    {
        cout << "unsolvable" << endl;
    }
    else
    {
        cout << G[id] << endl;;
    }
}

int main()
{
    Init();
    Bfs();
    while (cin >> ch[0] >> ch[1] >> ch[2] >> ch[3] >> ch[4] >> ch[5] >> ch[6] >> ch[7] >> ch[8])
    {
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
