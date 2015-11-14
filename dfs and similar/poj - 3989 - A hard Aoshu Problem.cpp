#include <cstdio>
#include <cstring>

const int MAXW = 8 + 5;
const int MAXN = 4 + 5;

int T;
char L[MAXW];
char R[MAXW];
char result[MAXW];
char allWord[MAXW * 3];
int ret;
int lLen;
int rLen;
int resultLen;
int allLen;

void Read()
{
	scanf("%s", L);
	scanf("%s", R);
	scanf("%s", result);
}

int digitIsUsed[10];
int val[MAXN];

void Dfs(int cur)
{
	if (cur == allLen)
	{
		int nL = 0;
		int nR = 0;
		int nResult = 0;

		for (int i = 0; i < lLen; ++i)
		{
			nL = nL * 10 + val[L[i] - 'A'];
		}
		for (int i = 0; i < rLen; ++i)
		{
			nR = nR * 10 + val[R[i] - 'A'];
		}
		for (int i = 0; i < resultLen; ++i)
		{
			nResult = nResult * 10 + val[result[i] - 'A'];
		}

		if (nL + nR == nResult)
		{
			++ret;
		}
		if (nL - nR == nResult)
		{
			++ret;
		}
		if (nL * nR == nResult)
		{
			++ret;
		}
		if (nR != 0 && nL % nR == 0 && nL / nR == nResult)
		{
			++ret;
		}

		return;
	}

	if (val[allWord[cur] - 'A'] != -1)
	{
		Dfs(cur + 1);
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (digitIsUsed[i] == false)
		{
			if (i == 0 && ((cur == 0 && lLen > 1) || (cur == lLen && rLen > 1) || (cur == lLen + rLen && resultLen > 1))) continue;
			val[allWord[cur] - 'A'] = i;
			digitIsUsed[i] = true;
			Dfs(cur + 1);
			digitIsUsed[i] = false;
			val[allWord[cur] - 'A'] = -1;
		}
	}
}

void Solve()
{
	ret = 0;
	lLen = strlen(L);
	rLen = strlen(R);
	resultLen = strlen(result);
	allLen = lLen + rLen + resultLen;
	allWord[0] = '\0';
	strcat(allWord, L);
	strcat(allWord, R);
	strcat(allWord, result);
	memset(digitIsUsed, 0, sizeof(digitIsUsed));
	memset(val, -1, sizeof(val));
	Dfs(0);
}

void Output()
{
	printf("%d\n", ret);
}

int main()
{
	// freopen("B.in", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		Read();
		Solve();
		Output();
	}

	return 0;
}