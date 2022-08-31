#include <iostream>

#define INT_MAX			2147483647
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

long long r[501];
long long c[501];

long long dp[501][501];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> r[i] >> c[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INT_MAX;

		}

	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i + k <= n; i++)
		{
			for (int m = i; m <= i + k; m++)
			{
				// i 부터 i+k, 즉 i부터 길이 k+1의 구간에 대한 최솟값은
				// i에서 i+k 사이의 값 m에 따라 m이 i 일때부터 i+k 일때까지 확인하면서
				// i부터 m까지, m+1부터 i+k까지에 해당되는 최솟값을 각각 구한 뒤, 
				// 두 최솟값에 대한 연산 수 중 가장 작은 것을 i부터 i+k까지의 최소 연산수로 저장
				dp[i][i + k] = MIN(dp[i][i + k], dp[i][m] + dp[m + 1][i + k] + r[i] * c[m] * c[i + k]);
			}
		}
		// 이를 구간이 2일 때(즉, k=1)부터 구간이 n일때(k=n-1)까지 순차적으로 구함
		// 즉, 최종적으로 dp[1][n]에 전체 구간에 대한 최솟값이 저장됨
	}

	cout << dp[1][n];

	return 0;
}