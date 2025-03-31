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

#define CITY_MAX		1000
#define TIME_MAX		100

using namespace std;

int n, m, x;
int map[CITY_MAX + 1][CITY_MAX + 1];

int dist[CITY_MAX + 1];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int start, int end)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	pq = {};
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int minDist = pq.top().first;
		int minIdx = pq.top().second;
		pq.pop();

		if (minIdx == end)
			break;

		// already checked
		if (dist[minIdx] < minDist)
			continue;

		for (int i = 1; i <= n; i++)
		{
			if (map[minIdx][i] != -1)
			{
				int newDist = minDist + map[minIdx][i];
				if (newDist < dist[i])
				{
					dist[i] = newDist;
					pq.push(make_pair(newDist, i));
				}
			}
		}
	}

	return dist[end];
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = -1;
	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		map[s][e] = t;
	}

	int maxTime = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == x)
			continue;
		int time = dijkstra(i + 1, x) + dijkstra(x, i + 1);
		maxTime = MAX(maxTime, time);
	}

	cout << maxTime << endl;

	return 0;
}