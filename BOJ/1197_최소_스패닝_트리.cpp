#include <iostream>
#include <queue>
#include <set>

#define endl "\n"

using namespace std;

struct Edge
{
	int s;
	int e;
	int w;
};

struct LessEdge
{
	bool operator()(Edge a, Edge b)
	{
		return a.w > b.w;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<vector<Edge>> adj(v);

	priority_queue<Edge, vector<Edge>, LessEdge> pq;

	for (int i = 0; i < e; i++)
	{
		Edge edge;
		cin >> edge.s >> edge.e >> edge.w;
		edge.s--;
		edge.e--;
		adj[edge.s].push_back(edge);

		Edge inverse;
		inverse.s = edge.e;
		inverse.e = edge.s;
		inverse.w = edge.w;
		adj[edge.e].push_back(inverse);
	}

	set<int> points;

	points.insert(0);
	for (int i = 0; i < adj[0].size(); i++)
	{
		pq.push(adj[0][i]);
	}

	long long weight = 0;

	while (!pq.empty())
	{
		Edge cur = pq.top();
		pq.pop();

		if (points.find(cur.e) != points.end())
			continue;

		weight += cur.w;
		points.insert(cur.e);

		for (int i = 0; i < adj[cur.e].size(); i++)
		{
			if (points.find(adj[cur.e][i].e) == points.end())
			{
				pq.push(adj[cur.e][i]);
			}
		}
	}

	cout << weight;

	return 0;
}