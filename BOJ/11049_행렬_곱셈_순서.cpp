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
				// i ���� i+k, �� i���� ���� k+1�� ������ ���� �ּڰ���
				// i���� i+k ������ �� m�� ���� m�� i �϶����� i+k �϶����� Ȯ���ϸ鼭
				// i���� m����, m+1���� i+k������ �ش�Ǵ� �ּڰ��� ���� ���� ��, 
				// �� �ּڰ��� ���� ���� �� �� ���� ���� ���� i���� i+k������ �ּ� ������� ����
				dp[i][i + k] = MIN(dp[i][i + k], dp[i][m] + dp[m + 1][i + k] + r[i] * c[m] * c[i + k]);
			}
		}
		// �̸� ������ 2�� ��(��, k=1)���� ������ n�϶�(k=n-1)���� ���������� ����
		// ��, ���������� dp[1][n]�� ��ü ������ ���� �ּڰ��� �����
	}

	cout << dp[1][n];

	return 0;
}