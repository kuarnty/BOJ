#include <iostream>
#include <vector>
#include <algorithm>
//strlen은 cstring에 있다 쓰레기같은거

#define MAXVALUE(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int length[100001];
bool visited[100001];

struct Node
{
	int id;
	int parent;
	// pair<nodeId, value>
	vector<pair<int, int>> adj;
};

vector<Node> graph;

int DFS(int id)
{
	visited[id] = true;

	int length1 = 0;
	int length2 = 0;

	for (int i = 0; i < graph[id].adj.size(); i++)
	{
		if (!visited[graph[id].adj[i].first])
		{
			int ln = DFS(graph[id].adj[i].first) + graph[id].adj[i].second;

			if (ln >= length1)
			{
				length2 = length1;
				length1 = ln;
			}
			else if (ln > length2)
			{
				length2 = ln;
			}
		}
	}

	length[id] = length1 + length2;

	return length1;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int v;
	cin >> v;
	graph.push_back({ 0, -1, });
	for (int i = 1; i <= v; i++)
	{
		graph.push_back({ i, -1, });
		visited[i] = false;
	}

	for (int i = 1; i <= v; i++)
	{
		int nodeNumber;
		cin >> nodeNumber;

		int destination, distance;
		while (true)
		{
			cin >> destination;
			if (destination == -1)
				break;

			cin >> distance;
			graph[nodeNumber].adj.push_back({ destination, distance });
		}
	}

	DFS(1);

	int maxLength = 0;
	for (int i = 1; i <= v; i++)
	{
		maxLength = MAXVALUE(maxLength, length[i]);
	}

	cout << maxLength;

	return 0;
}