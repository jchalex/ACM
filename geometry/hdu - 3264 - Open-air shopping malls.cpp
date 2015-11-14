#include <cstdio>
#include <cmath>
#include <algorithm>

using std::min;

const int MAXN = 20 + 5;
const double MAXR = 31000;
const double EPS = 1e-8;
const double PI = acos(-1);

typedef struct _POINT
{
	double x;
	double y;

	_POINT() {}
	_POINT(double x, double y): x(x), y(y) {}
} POINT, VECTOR;

VECTOR operator - (const VECTOR& a, const VECTOR& b)
{
	return VECTOR(a.x - b.x, a.y - b.y);
}

typedef struct _CIRCLE
{
	POINT c;
	double r;
	
	_CIRCLE() {}
	_CIRCLE(double x, double y, double r)
	{
		c.x = x;
		c.y = y;
		this->r = r;
	}
} CIRCLE;

int T;
int N;
double ret;
CIRCLE mall[MAXN];

int Dcmp(double x)
{
	if (fabs(x) < EPS) return 0;
	return x > 0 ? 1 : -1;
}

double Length(const VECTOR& a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

double CircleCircleArea(const CIRCLE& c1, const CIRCLE& c2)
{
	double ret = 0;
	double d = Length(c1.c - c2.c);

	if (Dcmp(d - c1.r - c2.r) < 0 && Dcmp(d - fabs(c1.r - c2.r)) > 0)
	{
		double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
		double b = acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));
		double area1 = a * c1.r * c1.r - c1.r * c1.r * sin(2 * a) / 2;
		double area2 = b * c2.r * c2.r - c2.r * c2.r * sin(2 * b) / 2;
		ret = area1 + area2;		
	}
	else if (Dcmp(d - fabs(c1.r - c2.r)) <= 0)
	{
		if (Dcmp(c1.r - c2.r) < 0)
		{
			ret = PI * c1.r * c1.r;
		}
		else
		{
			ret = PI * c2.r * c2.r;		
		}
	}

	return ret;
}

void Read()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf%lf%lf", &mall[i].c.x, &mall[i].c.y, &mall[i].r);
	}
}

bool isOk(int id, double r)
{
	bool ret = true;

	for (int i = 0; i < N; ++i)
	{
		double interArea = CircleCircleArea(CIRCLE(mall[id].c.x, mall[id].c.y, r), mall[i]);
		if (Dcmp(interArea - PI * mall[i].r * mall[i].r / 2) < 0)
		{
			ret = false;
			break;
		}
	}

	return ret;
}

void Solve()
{
	ret = MAXR;
	for (int i = 0; i < N; ++i)
	{
		double l = 0;
		double r = MAXR;

		while (Dcmp(l - r) < 0)
		{
			double m = (l + r) / 2;

			if (isOk(i, m))
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		ret = min(ret, l);
	}
}

void Output()
{
	printf("%.4f\n", ret);
}

int main()
{
	// freopen("a.in", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		Read();
		Solve();
		Output();
	}
}

/*

1
2
0 0 1
2 0 1

2.0882

*/