#include <vector>

#define ll long long

using namespace std;

void init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
}