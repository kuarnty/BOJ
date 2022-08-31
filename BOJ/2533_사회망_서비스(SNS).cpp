#include <iostream>
#include <vector>

#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

int n;

vector<int> graph[1000000];

int dpEarlyAdaptor[1000000];
int dpNotEarlyAdaptor[1000000];

bool visited[1000000];

void check(int node)
{
	visited[node] = true;
	dpEarlyAdaptor[node] = 1;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (visited[next])
			continue;
		else
		{
			check(next);
			// if current node is not early adaptor,
			// then all the next nodes have to be early adaptors.
			dpNotEarlyAdaptor[node] += dpEarlyAdaptor[next];
			// if current node is not early adaptor,
			// then every next nodes doesn't have to be early adaptor, but can be(and also might be) early adapter.
			dpEarlyAdaptor[node] += MIN(dpNotEarlyAdaptor[next], dpEarlyAdaptor[next]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	check(0);

	cout << MIN(dpEarlyAdaptor[0], dpNotEarlyAdaptor[0]);

	return 0;
}