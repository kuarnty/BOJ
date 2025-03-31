#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MIN(a, b) (a) < (b) ? (a) : (b)
#define INT_MAX 2147483647

using namespace std;

int n, m;
int s, t;
int dist[1001];
vector<pair<int, int>> vertexes[1001];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vertexes[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	cin >> s >> t;

	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty())
	{
		int curCost = -pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		if (curV == t)
			break;

		for (int i = 0; i < vertexes[curV].size(); i++)
		{
			int adjIndex = vertexes[curV][i].first;
			int adjCost = vertexes[curV][i].second;
			if (dist[adjIndex] > curCost + adjCost)
			{
				dist[adjIndex] = curCost + adjCost;
				pq.push(make_pair(-dist[adjIndex], adjIndex));
			}
		}
	}

	if (dist[t] == INT_MAX)
		cout << -1;
	else
		cout << dist[t];

	return 0;
}