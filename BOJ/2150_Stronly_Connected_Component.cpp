#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

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

using namespace std;

const int VERTICES = 10001;

vector<int> graph[VERTICES];

stack<int> s;
int id[VERTICES] = { 0 };
int curId = 0;
int SCCId[VERTICES];
vector<vector<int>> SCC;

int traverse(int node)
{
	// Set id as the visited order of node.
	id[node] = ++curId;
	s.push(node);

	int lowLink = id[node];

	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		// if not visited
		if (id[next] == 0)
		{
			int nextLowLink = traverse(next);
			lowLink = MIN(lowLink, nextLowLink);
		}
		// if visited(cycle is found), but not assigned yet
		else if (SCCId[next] == 0)
			lowLink = MIN(lowLink, id[next]);
	}

	// If there's a cycle from node* to itself, or no cycle
	// add a SCC and assign nodes in stack. (nodes in the cycle are in the stack)
	if (lowLink == id[node])
	{
		SCC.push_back(vector<int>());
		while (true)
		{
			int top = s.top();
			s.pop();

			SCCId[top] = SCC.size();
			SCC[SCCId[top] - 1].push_back(top);

			if (top == node)
				break;
		}
	}

	return lowLink;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	while (e--)
	{
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
	}

	for (int i = 1; i <= v; i++)
		if (id[i] == 0)
			traverse(i);

	// Sort
	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end());
	/*for (auto& vec : SCC)
		sort(vec.begin(), vec.end());
	sort(SCC.begin(), SCC.end());*/


	cout << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << ' ';
		cout << "-1" << endl;
	}

	return 0;
}