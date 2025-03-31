#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <map>

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

#define CNT_MAX			8

using namespace std;

int n, m;
map<int, int> nums;
map<int, int> numUsed;
int arr[CNT_MAX] = { 0 };

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ((i == m - 1) ? "" : " ");
		}
		cout << '\n';
	}
	for (auto num = nums.begin(); num != nums.end(); num++)
	{
		if (numUsed[num->first] < num->second)
		{
			numUsed[num->first]++;
			arr[cnt] = num->first;
			dfs(cnt + 1);
			numUsed[num->first]--;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums[num]++;
		numUsed[num] = 0;
	}

	dfs(0);

	return 0;
}