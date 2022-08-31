#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

bool edges[1000][1000];
bool visited[1000];
bool visiting[1000];
vector<int> line;

void dfs(int node, int n)
{
	visited[node] = true;
	visiting[node] = true;

	for (int i = 0; i < n; i++)
	{
		if (node != i && edges[node][i])
		{
			if (visiting[i])
			{
				cout << 0 << endl;
				exit(0);
			}
			if (!visited[i])
			{
				dfs(i, n);
			}
		}
	}
	line.push_back(node);
	visiting[node] = false;
}

void topologicalSort(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, n);
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

	if (n == 1)
	{
		cout << 1 << endl;
		exit(0);
	}

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		vector<int> order(t);
		for (int j = 0; j < t; j++)
		{
			cin >> order[j];
		}
		for (int j = 0; j < t - 1; j++)
		{
			edges[order[j] - 1][order[j + 1] - 1] = true;
		}
	}

	topologicalSort(n);

	for (int i = n - 1; i >= 0; i--)
	{
		cout << line[i] + 1 << endl;
	}

	return 0;
}