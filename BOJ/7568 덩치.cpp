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

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> wh(n);
	for (int i = 0; i < n; i++)
		cin >> wh[i].first >> wh[i].second;

	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (wh[j].first > wh[i].first && wh[j].second > wh[i].second)
				cnt++;
		}
		cout << cnt << ((i < n - 1) ? " " : "");
	}

	return 0;
}