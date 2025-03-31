#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <memory.h>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

#define TREE_HEIGHT		17 // ceil(log(100000))
#define MAX_NODES		100000

using namespace std;

vector<pair<int, int>> adj[MAX_NODES + 1]; // first: destination, second: length of road
int n, parents[MAX_NODES + 1][TREE_HEIGHT], level[MAX_NODES + 1];
pair<int, int> roadLen[MAX_NODES + 1][TREE_HEIGHT];	// first: min, second: max

void buildTree(int curNode, int parentNode, int lev, int len)
{
	level[curNode] = lev;
	parents[curNode][0] = parentNode;
	roadLen[curNode][0] = { len, len };

	for (int i = 0; i < adj[curNode].size(); i++)
		if (adj[curNode][i].first != parentNode)
			buildTree(adj[curNode][i].first, curNode, lev + 1, adj[curNode][i].second);
	return;
}

pair<int, int> FindLen(int a, int b)
{
	int minLen = INT_MAX, maxLen = -1;

	// set a deeper node
	if (level[a] < level[b])
		swap(a, b);

	// set a and b to the same level
	int dist = level[a] - level[b];
	for (int i = 0; dist > 0; i++)
	{
		if (dist % 2 != 0)
		{
			minLen = min(minLen, roadLen[a][i].first);
			maxLen = max(maxLen, roadLen[a][i].second);
			a = parents[a][i];
		}
		dist = dist >> 1;
	}

	// if a and b are at the same level, but not same -> find common ancestor
	if (a != b)
	{
		for (int i = TREE_HEIGHT - 1; i >= 0; i--)
		{
			if (parents[a][i] != 0 && parents[a][i] != parents[b][i])
			{
				minLen = min(minLen, min(roadLen[a][i].first, roadLen[b][i].first));
				maxLen = max(maxLen, max(roadLen[a][i].second, roadLen[b][i].second));
				a = parents[a][i];
				b = parents[b][i];
			}
		}
		minLen = min(minLen, min(roadLen[a][0].first, roadLen[b][0].first));
		maxLen = max(maxLen, max(roadLen[a][0].second, roadLen[b][0].second));
	}

	return { minLen, maxLen };
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	memset(parents, 0, sizeof(parents));

	buildTree(1, 0, 0, 0);

	// set min, max len to parents
	for (int k = 1; k < TREE_HEIGHT; k++)
	{
		for (int i = 2; i <= MAX_NODES; i++)
		{
			if (parents[i][k - 1] != 0)
			{
				parents[i][k] = parents[parents[i][k - 1]][k - 1];
				roadLen[i][k].first = min(roadLen[i][k - 1].first, roadLen[parents[i][k - 1]][k - 1].first);
				roadLen[i][k].second = max(roadLen[i][k - 1].second, roadLen[parents[i][k - 1]][k - 1].second);
			}
		}
	}

	int k;
	cin >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> len = FindLen(a, b);
		cout << len.first << " " << len.second << endl;
	}

	return 0;
}