#include <iostream>

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))

using namespace std;

// dp[i][j] = (1부터) i번째 앱까지 비용 j로 얻을 수 있는 최대 메모리
int dp[101][10001];
int mem[101];
int cost[101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> mem[i];

	int costSum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		costSum += cost[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= costSum; j++)
		{
			// 비용 제한 j에서 i번째 앱을 추가할 여유가 있는 경우
			if (j - cost[i] >= 0)
				dp[i][j] = dp[i - 1][j - cost[i]] + mem[i];

			// i번째 앱을 추가할 수 없었다면: 그냥 직전(i-1번째 앱까지) 경우의 값을 넣게 되고,
			// i번째 앱을 추가할 수 있었다면: i번째 앱을 추가한 경우와, 그냥 j번째까지 확인했을 때 최댓값, 중 얻는 메모리가 더 큰 경우를 선택
			dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
		}
	}

	// 비용(i)이 가장 작은 경우부터 차례대로 검사하여
	for (int i = 0; i <= costSum; i++)
	{
		// n번째 앱까지 모두 체크한 결과에서
		// 얻는 메모리가 m 이상인 경우가 있으면
		// 최소 비용으로 m 이상의 메모리를 얻는 경우이므로 출력
		if (dp[n][i] >= m)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}