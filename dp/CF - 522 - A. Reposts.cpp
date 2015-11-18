#include <iostream>
#include <string>
#include <map>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int n;
int ret;
map<string, int> G;

void Init()
{
	G.clear();
	G["polycarp"] = 1;
	ret = 0;
}

void Read()
{
	string s1;
	string s2;

	while (n--)
	{	
		cin >> s1 >> s2 >> s2;
		for (int i = 0; i < s1.length(); ++i)
		{
			s1[i] = tolower(s1[i]);
		}
		for (int i = 0; i < s2.length(); ++i)
		{
			s2[i] = tolower(s2[i]);
		}
		G[s1] = G[s2] + 1;
		if (G[s1] > ret)
		{
			ret = G[s1];
		}
	}
}

void Output()
{
	cout << ret << endl;
}

int main()
{
	// freopen("a.in", "r", stdin);
	while (cin >> n)
	{
		Init();
		Read();
		Output();
	}

	return 0;
}