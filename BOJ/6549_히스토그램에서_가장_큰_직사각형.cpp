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

using namespace std;

int n;

vector<int> heights;

long long solve(int left, int right)
{
	if (left == right)
		return heights[left];

	int mid = (left + right) / 2;
	long long lAns = solve(left, mid);
	long long rAns = solve(mid + 1, right);
	long long ans = MAX(lAns, rAns);

	int l = mid;
	int r = mid + 1;
	long long minHeight = INT_MAX;
	// while calculating (ans = MAX(ans, ((r - l + 1) * minHeight));) <- this, 
	// the result over the range of int. Thus, minHeight has to be long long type (or r, l)
	while (left <= l && r <= right)
	{
		minHeight = MIN(minHeight, MIN(heights[l], heights[r]));
		ans = MAX(ans, ((r - l + 1) * minHeight));
		if (left == l)
			r++;
		else if (right == r)
			l--;
		else if (heights[l - 1] <= heights[r + 1])
			r++;
		else
			l--;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		cin >> n;
		if (n == 0)
			return 0;

		heights.resize(n);
		for (int i = 0; i < n; i++)
			cin >> heights[i];
		cout << solve(0, n - 1) << endl;
	}

	return 0;
}