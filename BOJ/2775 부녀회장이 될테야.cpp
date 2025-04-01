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

	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		vector<vector<int>> apt(k + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++)
			apt[0][i] = i;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				apt[i][j] = apt[i][j - 1] + apt[i - 1][j];

		cout << apt[k][n] << endl;
	}

	return 0;
}