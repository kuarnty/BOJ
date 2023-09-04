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

int all = (1 << 10) - 1;
int dp[101][10][1 << 10];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= all; k++)
			{
				if (j > 0)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
				if (j < 9)
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
			}

	int ans = 0;

	for (int i = 0; i <= 9; i++)
		ans = (ans + dp[n][i][all]) % 1000000000;

	cout << ans;

	return 0;
}