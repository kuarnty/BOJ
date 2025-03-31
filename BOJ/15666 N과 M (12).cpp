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

#define CNT_MAX			8

using namespace std;

int n, m;
map<int, int> nums;
int arr[CNT_MAX] = { 0 };

void dfs(int lastNum, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ((i == m - 1) ? "" : " ");
		cout << '\n';
		return;
	}

	for (auto num = nums.begin(); num != nums.end(); num++)
	{
		if (num->first < lastNum)
			continue;
		else
		{
			arr[cnt] = num->first;
			dfs(num->first, cnt + 1);
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
	}

	dfs(0, 0);

	return 0;
}