#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <queue>
#include <memory.h>

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

using namespace std;

int map[1000][1000];
int nav[1000][1000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int startX, startY;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				startX = i;
				startY = j;
			}
		}

	memset(nav, -1, sizeof(nav));
	nav[startX][startY] = 0;

	queue<pair<int, int>> q;
	q.push({ startX, startY });
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		int curDist = nav[x][y];

		if (x > 0 && map[x - 1][y] == 1 && nav[x - 1][y] == -1)
		{
			nav[x - 1][y] = curDist + 1;
			q.push({ x - 1, y });
		}
		if (x < n - 1 && map[x + 1][y] == 1 && nav[x + 1][y] == -1)
		{
			nav[x + 1][y] = curDist + 1;
			q.push({ x + 1, y });
		}
		if (y > 0 && map[x][y - 1] == 1 && nav[x][y - 1] == -1)
		{
			nav[x][y - 1] = curDist + 1;
			q.push({ x, y - 1 });
		}
		if (y < m - 1 && map[x][y + 1] == 1 && nav[x][y + 1] == -1)
		{
			nav[x][y + 1] = curDist + 1;
			q.push({ x, y + 1 });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << (nav[i][j] == -1 ? (map[i][j] == 0 ? 0 : -1) : nav[i][j]) << (j == m - 1 ? "" : " ");
		cout << endl;
	}

	return 0;
}