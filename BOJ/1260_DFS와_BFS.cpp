#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

bool g[1001][1001];
bool visited[1001];

void DFS(int node, int n)
{
	visited[node] = true;
	cout << node << ' ';

	for (int i = 1; i <= n; i++)
		if (node != i && g[node][i])
			if (!visited[i])
				DFS(i, n);
}

void BFS(int node, int n)
{
	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;
		cout << cur << ' ';

		for (int i = 1; i <= n; i++)
			if (cur != i && g[cur][i])
				if (!visited[i])
					q.push(i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		g[s][e] = true;
		g[e][s] = true;
	}

	DFS(v, n);
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	BFS(v, n);

	return 0;
}