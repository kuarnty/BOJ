#include <iostream>
#include <vector>
#include <algorithm>
//strlen은 cstring에 있다 쓰레기같은거

#define MAXVALUE(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int length[10001];

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
	int length1 = 0;
	int length2 = 0;

	for (int i = 0; i < graph[id].adj.size(); i++)
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

	length[id] = length1 + length2;

	return length1;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	graph.push_back({ 0, -1, });
	for (int i = 0; i < n; i++)
	{
		graph.push_back({ i + 1, -1, });
	}

	for (int i = 0; i < n - 1; i++)
	{
		int p, c, v;
		cin >> p >> c >> v;
		graph[p].adj.push_back({ c, v });
		graph[c].parent = p;
	}

	DFS(1);

	int maxLength = 0;
	for (int i = 1; i <= n; i++)
	{
		maxLength = MAXVALUE(maxLength, length[i]);
	}

	cout << maxLength;

	return 0;
}