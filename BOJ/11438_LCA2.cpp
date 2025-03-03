#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

#define MAXLEVEL 16		// floor(log2(100001))

using namespace std;

int n, m;
vector<int> tree[100001];
int parent[100001][18];
int level[100001];

// Set the level of current node and parent nodes.
void set_tree(int curNode, int pNode, int lv)
{
	level[curNode] = lv;
	parent[curNode][0] = pNode;

	// Set parent nodes
	for (int i = 1; i <= MAXLEVEL; i++)
		// (2^i)th parent of curNode is (the 2^(i-1)th parent node of (the 2^(i-1)th parent node of current node)) (2^(i-1)+2^(i-1) = 2^i)
		parent[curNode][i] = parent[(parent[curNode][i - 1])][i - 1];
	
	// Connect child nodes
	for (int i = 0; i < tree[curNode].size(); i++)
	{
		int childnode = tree[curNode][i];
		
		// if the child node (connected node) is already checked just before. (actually its the parent node in this case)
		if (childnode == pNode)
			continue;
		// else, the child node is really child of this node.
		set_tree(childnode, curNode, lv + 1);
	}
}

// Find the LCA of two nodes.
int LCA(int a, int b)
{
	// if any of two is the root.
	// in this case, we need to return 1 manually, because all parent nodes of root is 0 (non-exist)
	if (a == 1 || b == 1)
		return 1;

	// Set *a* node deeper(higher level).
	if (level[a] < level[b])
	{
		int c = a;
		a = b;
		b = c;
	}

	// If levels of two are difference, find the ancestor of deeper one(a) which has same level of the another.
	if (level[a] != level[b])
		// Start jumping to an ancestor with the largeast gap (i = MAXLEVEL) (same for the below)
		for (int i = MAXLEVEL; i >= 0; i--)
			if (level[parent[a][i]] >= level[b])
				a = parent[a][i];

	int ret = a;
	if (a != b)
	{
		for (int i = MAXLEVEL; i >= 0; i--)
		{
			// If the (2^i)th parents of two are different, we need to check lower nodes
			if (parent[a][i] != parent[b][i])
			{
				a = parent[a][i];
				b = parent[b][i];
			}
			// Finally, *ret* is set as the (2^0)st parent node of *a* where the (2^0)st parent node of two are same
			ret = parent[a][i];
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	while (--n)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	set_tree(1, 0, 1);

	cin >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}

	return 0;
}