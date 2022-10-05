#include <iostream>
#include <vector>
#include <string>

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

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string s;
	cin >> s;
	int n = s.length();

	vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
		isPalindrome[i][i] = true;

	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
			isPalindrome[i][i + 1] = true;

	for (int len = 3; len <= n; len++)
	{
		for (int start = 0; start + len - 1 < n; start++)
		{
			int end = start + len - 1;
			if (s[start] == s[end] && isPalindrome[start + 1][end - 1])
				isPalindrome[start][end] = true;
		}
	}

	vector<int> dp(n, INT_MAX);
	dp[0] = 1;

	for (int end = 0; end < n; end++)
	{
		for (int start = 0; start <= end; start++)
		{
			if (isPalindrome[start][end])
			{
				if (start == 0)
					dp[end] = 1;
				else
					dp[end] = MIN(dp[end], dp[start - 1] + 1);
			}
		}
	}

	cout << dp[n - 1] << endl;

	return 0;
}