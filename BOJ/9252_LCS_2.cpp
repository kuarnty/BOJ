#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXVALUE(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int s[1002][1002] = { 0 };
pair<int, int> p[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	char a[1002];
	char b[1002];

	cin >> a >> b;

	int lengthA = strlen(a);
	int lengthB = strlen(b);

	for (int i = 1; i <= lengthA; i++)
	{
		for (int j = 1; j <= lengthB; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				s[i][j] = s[i - 1][j - 1] + 1;
				p[i][j] = { i - 1,j - 1 };
			}
			else
			{
				if (s[i - 1][j] > s[i][j - 1])
				{
					s[i][j] = s[i - 1][j];
					p[i][j] = { i - 1,j };
				}
				else
				{
					s[i][j] = s[i][j - 1];
					p[i][j] = { i, j - 1 };
				}
			}
		}
	}

	cout << s[lengthA][lengthB];

	//for (int i = 0; i <= lengthA; i++)
	//{
	//	for (int j = 0; j <= lengthB; j++)
	//	{
	//		cout << "<" << p[i][j].first << " " << p[i][j].second << "> ";
	//	}
	//	cout << endl;
	//}

	pair<int, int> pos = { lengthA, lengthB };
	string result;

	for (int i = 0; i < s[lengthA][lengthB]; i++)
	{
		while (p[pos.first][pos.second].first != pos.first - 1 || p[pos.first][pos.second].second != pos.second - 1)
			pos = p[pos.first][pos.second];

		pos = p[pos.first][pos.second];

		result.push_back(a[pos.first]);
	}

	reverse(result.begin(), result.end());
	if (s[lengthA][lengthB] != 0)
		cout << endl << result;

	return 0;
}