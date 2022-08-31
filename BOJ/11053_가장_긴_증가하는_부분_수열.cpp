#include <iostream>
#include <vector>
#include <queue>

#define MAXVALUE(A, B) (A) > (B) ? (A) : (B)

using namespace std;

int val[1000];
int dp[1000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
		dp[i] = 1;
	}

	int max = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (val[i] > val[j])
				dp[i] = MAXVALUE(dp[i], dp[j] + 1);
		}
		max = MAXVALUE(max, dp[i]);
	}

	cout << max;

	return 0;
}