#include <iostream>

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))

using namespace std;

// dp[i][j] = (1����) i��° �۱��� ��� j�� ���� �� �ִ� �ִ� �޸�
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
			// ��� ���� j���� i��° ���� �߰��� ������ �ִ� ���
			if (j - cost[i] >= 0)
				dp[i][j] = dp[i - 1][j - cost[i]] + mem[i];

			// i��° ���� �߰��� �� �����ٸ�: �׳� ����(i-1��° �۱���) ����� ���� �ְ� �ǰ�,
			// i��° ���� �߰��� �� �־��ٸ�: i��° ���� �߰��� ����, �׳� j��°���� Ȯ������ �� �ִ�, �� ��� �޸𸮰� �� ū ��츦 ����
			dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
		}
	}

	// ���(i)�� ���� ���� ������ ���ʴ�� �˻��Ͽ�
	for (int i = 0; i <= costSum; i++)
	{
		// n��° �۱��� ��� üũ�� �������
		// ��� �޸𸮰� m �̻��� ��찡 ������
		// �ּ� ������� m �̻��� �޸𸮸� ��� ����̹Ƿ� ���
		if (dp[n][i] >= m)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}