#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define endl            '\n'
#define MAX_JUMP        16      // ceil(log2(40000)) (2^16 = 65536)
#define MAX_NODES       40000

using namespace std;

int n, m;
// <child node, distance>
vector<pair<int, int>> tree[MAX_NODES + 1];
int parent[MAX_NODES + 1][MAX_JUMP + 1];
int level[MAX_NODES + 1];

// distance from the root
long long dists[MAX_NODES + 1] = { 0, };

// Set level of current node, parent node, distance from root.
void set_tree(int curNode, int pNode, int lv, long long dist)
{
	parent[curNode][0] = pNode;
	level[curNode] = lv;
	dists[curNode] = dists[pNode] + dist;

	int logLevel = ceil(log2(lv - 1));
	// int logLevel = floor(log2(lv));	// same above

	// Set parent nodes.
	for (int i = 1; i <= logLevel; i++)
		parent[curNode][i] = parent[parent[curNode][i - 1]][i - 1];

	// Connect child nodes.
	for (int i = 0; i < tree[curNode].size(); i++)
	{
		int childNode = tree[curNode][i].first;
		long long childDist = tree[curNode][i].second;

		if (childNode == pNode)
			continue;
		else
			set_tree(childNode, curNode, lv + 1, childDist);
	}
}

// Find the LCA of two nodes.
int LCA(int a, int b)
{
	// Set *a* node deeper(higher level).
	if (level[a] < level[b])
		swap(a, b);

	// If levels of two are different, find the ancestor of deeper one(a) which has same level of the another.
	if (level[a] != level[b])
		for (int i = MAX_JUMP; i >= 0; i--)
			if (level[a] - (1 << i) >= level[b])
				a = parent[a][i];

	// Find lca
	if (a != b)
	{
		for (int i = MAX_JUMP; i >= 0; i--)
		{
			if (parent[a][i] != parent[b][i])
			{
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}

	return a;
}

// Calculate distance of two nodes.
long long calculateDistance(int a, int b)
{
	int lca = LCA(a, b);
	return dists[a] + dists[b] - 2 * dists[lca];
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	for (int i = 0; i <= n; i++)
		fill(parent[i], parent[i] + MAX_JUMP + 1, -1);

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	set_tree(1, 0, 1, 0);

	cin >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << calculateDistance(a, b) << endl;
	}

	return 0;
}