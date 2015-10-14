#include <cstdio>
#include <cmath>

typedef struct _POINT
{
    double x;
    double y;

    _POINT(){}
    _POINT(double _x, double _y):x(_x), y(_y){}
} POINT;

typedef POINT VECTOR;

VECTOR operator - (VECTOR A, VECTOR B)
{
    return VECTOR(A.x - B.x, A.y - B.y);
}

double Cross(VECTOR A, VECTOR B)
{
    return A.x * B.y - A.y * B.x;
}

double Area(VECTOR A, VECTOR B, VECTOR C)
{
    return Cross(B - A, C - A) / 2;
}

POINT A, B, C;
int ret;

void Read()
{
    scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
}

void Solve()
{
    ret = fabs(Area(A, B, C) / 7) + 0.5;
}

void Output()
{
    printf("%d\n", ret);
}

int main()
{
    int N;

    scanf("%d", &N);
    while (N--)
    {
        Read();
        Solve();
        Output();
    }

    return 0;
}

/*

Sample Input
2
3994.707 9251.677 4152.916 7157.810 5156.835 2551.972
6903.233 3540.932 5171.382 3708.015 213.959 2519.852

Sample Output
98099
206144

*/
