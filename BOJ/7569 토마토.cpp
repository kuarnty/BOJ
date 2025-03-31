/*
	Mistake on the first try: 
		search all the nearyby unripes of ripes now(just before) and push to queue
		-> mark the nearby unripes as ripe and search all the nearbies repeatly
		=> too many duplicates of nearby unripes may be pushed to the queue
	Sol:
		Not to push duplicates, for each ripes
		before pushing unripes, mark they as ripe first, and push.
		Instead, we need to use the # of tomatos while checking the ripes now(same for BFS)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <queue>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

#define MAX_M	100
#define MAX_N	100
#define MAX_H	100

using namespace std;

int m, n, h;
int tomato[MAX_M][MAX_N][MAX_H];

struct Pos
{
	int x, y, z;
};

void printBox(int day, int nextRipesSize)
{
	cout << "day: " << day << endl;
	cout << "next ripes: " << nextRipesSize << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
				cout << tomato[k][j][i] << ' ';
			cout << endl;
		}
		cout << endl;
	}

	cout << endl << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	queue<pair<pair<int, int>, int>> todayRipe;

	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
			{
				cin >> tomato[k][j][i];
				if (tomato[k][j][i] == 1)
					todayRipe.push({ { k, j }, i });
			}

	int day = 0;
	int dk[6] = { -1, 1, 0, 0, 0, 0 };
	int dj[6] = { 0, 0, -1, 1, 0, 0 };
	int di[6] = { 0, 0, 0, 0, -1, 1 };

	while (todayRipe.size() > 0)
	{
		int cnt = todayRipe.size();
		while (cnt--)
		{
			pair<pair<int, int>, int> t = todayRipe.front();
			todayRipe.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int k = t.first.first + dk[dir];
				int j = t.first.second + dj[dir];
				int i = t.second + di[dir];
				if (k >= 0 && k < m && j >= 0 && j < n && i >= 0 && i < h
					&& tomato[k][j][i] == 0)
				{
					tomato[k][j][i] = day + 1;
					todayRipe.push({ {k, j}, i });
				}
			}
		}

		//printBox(day, todayRipe.size());

		if (todayRipe.empty())
			break;

		day++;

	}

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
				if (tomato[k][j][i] == 0)
				{
					cout << -1 << endl;
					return 0;
				}
	cout << day << endl;

	return 0;
}