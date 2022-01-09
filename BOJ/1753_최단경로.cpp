//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//#define MIN(a, b) a < b ? a : b
//#define MAX 2147483647
//
//using namespace std;
//
//vector<pair<int, int>> vertexes[20001];
//int dist[20001];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int v, e;
//	std::cin >> v >> e;
//
//	int k;
//	std::cin >> k;
//	for (int i = 0; i < e; i++)
//	{
//		int u, v, w;
//		std::cin >> u >> v >> w;
//		vertexes[u].push_back(make_pair(v, w));
//	}
//	for (int i = 1; i <= v; i++)
//	{
//		dist[i] = MAX;
//	}
//
//#pragma region Dijkstra
//
//	dist[k] = 0;
//	priority_queue<pair<int, int>> pq;
//	pq.push(make_pair(0, k));
//
//	while (!pq.empty())
//	{
//		int curCost = -pq.top().first;
//		int curV = pq.top().second;
//		pq.pop();
//
//		for (int i = 0; i < vertexes[curV].size(); i++)
//		{
//			int adjIndex = vertexes[curV][i].first;
//
//			if (dist[adjIndex] > curCost + vertexes[curV][i].second)
//			{
//				dist[adjIndex] = curCost + vertexes[curV][i].second;
//				pq.push(make_pair(-dist[adjIndex], adjIndex));
//			}
//		}
//	}
//
//#pragma endregion
//
//	for (int i = 1; i <= v; i++)
//	{
//		if (dist[i] == MAX)
//			cout << "INF" << '\n';
//		else
//			cout << dist[i] << '\n';
//	}
//
//	return 0;
//}