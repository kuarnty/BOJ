#include <iostream>
#include <string>
//strlen은 cstring에 있다 쓰레기같은거

#pragma warning(disable:4996)

using namespace std;

char map[65][65];

string QT(int log, int x, int y)
{
	if (log == 0)
	{
		string s;
		s.push_back(map[x][y]);
		return s;
	}
	else
	{
		int length = 1 << (log - 1);
		string s1, s2, s3, s4;
		s1 = QT(log - 1, x, y);
		s2 = QT(log - 1, x, y + length);
		s3 = QT(log - 1, x + length, y);
		s4 = QT(log - 1, x + length, y + length);

		if (s1 == s2 && s2 == s3 && s3 == s4 && (s1 == "1" || s1 == "0"))
			return s1;
		else
			return "(" + s1 + s2 + s3 + s4 + ")";
	}
}

int main()
{
	int n;
	cin >> n;

	string s;

	if (n == 1)
	{
		string s;
		cin >> s;
		cout << "(" << s[0] << ")";
		return 0;
	}


	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j];
		}
	}

	int log = 0;
	while (n /= 2)
		log++;

	string result = QT(log, 0, 0);

	cout << result;

	return 0;
}