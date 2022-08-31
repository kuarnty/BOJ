#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

vector<vector<int>> edges;
vector<int> line;
vector<int> visited;

void dfs(int node)
{
	visited[node] = true;

	for (int i = 0; i < edges[node].size(); i++)
	{
		if (!visited[edges[node][i]])
		{
			dfs(edges[node][i]);
		}
	}
	line.push_back(node);
}

void topologicalSort()
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		edges.push_back(vector<int>());
		visited.push_back(0);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].push_back(b - 1);
	}

	topologicalSort();

	for (int i = n-1; i >= 0; i--)
	{
		cout << line[i] + 1 << ' ';
	}

	return 0;
}