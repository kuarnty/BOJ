#include <iostream>
#include <queue>
#include <algorithm>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

int dist[100001];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	// pair<time, location>
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, n });

	int result = 0;

	for (int i = 0; i < 100001; i++)
	{
		dist[i] = -1;
	}
	dist[n] = 0;

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (cur.second == k)
		{
			cout << dist[cur.second];
			// or
			// cout << cur.first;
			return 0;
		}
		if (cur.second * 2 <= 100000)
		{
			if (dist[cur.second * 2] == -1 || dist[cur.second * 2] > cur.first)
			{
				dist[cur.second * 2] = cur.first;
				pq.emplace(cur.first, cur.second * 2);
			}
		}
		if (cur.second + 1 <= 100000)
		{
			if (dist[cur.second + 1] == -1 || dist[cur.second + 1] > cur.first + 1)
			{
				dist[cur.second + 1] = cur.first + 1;
				pq.emplace(cur.first + 1, cur.second + 1);
			}
		}
		if (cur.second - 1 >= 0)
		{
			if (dist[cur.second - 1] == -1 || dist[cur.second - 1] > cur.first + 1)
			{
				dist[cur.second - 1] = cur.first + 1;
				pq.emplace(cur.first + 1, cur.second - 1);
			}
		}
	}

	return 0;
}