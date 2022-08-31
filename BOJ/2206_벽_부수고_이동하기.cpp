#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
//strlen은 cstring에 있다 쓰레기같은거

#define MIN(A,B) (A) < (B) ? (A) : (B)
#define MAXVALUE 10000000

using namespace std;

int map[1000][1000];
int route1[1000][1000];
int route2[1000][1000];

struct Point
{
	int x;
	int y;
	int dist;
};

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] == '0' ? 0 : 1;
			route1[i][j] = MAXVALUE;
			route2[i][j] = MAXVALUE;
		}
	}

	route1[0][0] = 1;

	queue<pair<Point, bool>> q;
	q.push({ {0,0,1}, false });

	while (!q.empty())
	{
		pair<Point, bool> cur = q.front();
		q.pop();

		// 벽을 1번 부순 경우
		if (cur.second)
		{
			if (cur.first.y > 0)
			{
				int left = map[cur.first.x][cur.first.y - 1];
				if (left == 0 && route2[cur.first.x][cur.first.y - 1] > cur.first.dist + 1)
				{
					route2[cur.first.x][cur.first.y - 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y - 1, cur.first.dist + 1}, true });
				}
			}
			if (cur.first.y < m - 1)
			{
				int right = map[cur.first.x][cur.first.y + 1];
				if (right == 0 && route2[cur.first.x][cur.first.y + 1] > cur.first.dist + 1)
				{
					route2[cur.first.x][cur.first.y + 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y + 1, cur.first.dist + 1}, true });
				}
			}
			if (cur.first.x > 0)
			{
				int up = map[cur.first.x - 1][cur.first.y];
				if (up == 0 && route2[cur.first.x - 1][cur.first.y] > cur.first.dist + 1)
				{
					route2[cur.first.x - 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x - 1, cur.first.y, cur.first.dist + 1}, true });
				}
			}
			if (cur.first.x < n - 1)
			{
				int down = map[cur.first.x + 1][cur.first.y];
				if (down == 0 && route2[cur.first.x + 1][cur.first.y] > cur.first.dist + 1)
				{
					route2[cur.first.x + 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x + 1, cur.first.y, cur.first.dist + 1}, true });
				}
			}
		}
		// 아직 벽을 부수지 않은 경우
		else
		{
			if (cur.first.y > 0)
			{
				int left = map[cur.first.x][cur.first.y - 1];
				if (left == 1 && route2[cur.first.x][cur.first.y - 1] > cur.first.dist + 1)
				{
					route2[cur.first.x][cur.first.y - 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y - 1, cur.first.dist + 1}, true });
				}
				if (left == 0 && route1[cur.first.x][cur.first.y - 1] > cur.first.dist + 1)
				{
					route1[cur.first.x][cur.first.y - 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y - 1, cur.first.dist + 1}, false });
				}
			}
			if (cur.first.y < m - 1)
			{
				int right = map[cur.first.x][cur.first.y + 1];
				if (right == 1 && route2[cur.first.x][cur.first.y + 1] > cur.first.dist + 1)
				{
					route2[cur.first.x][cur.first.y + 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y + 1, cur.first.dist + 1}, true });
				}
				if (right == 0 && route1[cur.first.x][cur.first.y + 1] > cur.first.dist + 1)
				{
					route1[cur.first.x][cur.first.y + 1] = cur.first.dist + 1;
					q.push({ {cur.first.x, cur.first.y + 1, cur.first.dist + 1}, false });
				}
			}
			if (cur.first.x > 0)
			{
				int up = map[cur.first.x - 1][cur.first.y];
				if (up == 1 && route2[cur.first.x - 1][cur.first.y] > cur.first.dist + 1)
				{
					route2[cur.first.x - 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x - 1, cur.first.y , cur.first.dist + 1}, true });
				}
				if (up == 0 && route1[cur.first.x - 1][cur.first.y] > cur.first.dist + 1)
				{
					route1[cur.first.x - 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x - 1, cur.first.y, cur.first.dist + 1}, false });
				}
			}
			if (cur.first.x < n - 1)
			{
				int down = map[cur.first.x + 1][cur.first.y];
				if (down == 1 && route2[cur.first.x + 1][cur.first.y] > cur.first.dist + 1)
				{
					route2[cur.first.x + 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x + 1, cur.first.y , cur.first.dist + 1}, true });
				}
				if (down == 0 && route1[cur.first.x + 1][cur.first.y] > cur.first.dist + 1)
				{
					route1[cur.first.x + 1][cur.first.y] = cur.first.dist + 1;
					q.push({ {cur.first.x + 1, cur.first.y , cur.first.dist + 1}, false });
				}
			}
		}

		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int c = route2[i][j] == MAXVALUE ? 0 : route2[i][j];
				cout << c;
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;*/
	}

	int r1 = route1[n - 1][m - 1];
	int r2 = route2[n - 1][m - 1];
	if (r1 == MAXVALUE && r2 == MAXVALUE)
	{
		cout << -1;
	}
	else if (r1 != MAXVALUE && r2 != MAXVALUE)
	{
		int result = MIN(r1, r2);
		cout << result;
	}
	else
	{
		int result = r1 == MAXVALUE ? r2 : r1;
		cout << result;
	}

	return 0;
}