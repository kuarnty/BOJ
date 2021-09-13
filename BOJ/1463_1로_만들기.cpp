//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string.h>
//
//#define min(x,y) x<=y ? x:y
//#define INF 987654321
//
//using namespace std;
//
//int dp[1000001];
//
//int Solve(int n)
//{
//	if (n == 1)
//		return 0;
//
//	if (dp[n] != -1)
//		return dp[n];
//
//	int ret = INF;
//
//	if (n % 2 == 0)
//		ret = 1 + Solve(n / 2);
//	if (n % 3 == 0)
//		ret = min(ret, 1 + Solve(n / 3));
//
//	// 2 �Ǵ� 3���� ������ ������ ��� �� �� ��� ������ ������ �� ������ �� �� ������
//	// ��� ���̵� 1�� ���� �� ���ٴ� ���� ���̹Ƿ� 1�� ���� ������ 2�� 3 �� �� ��� �����ε� ���� �� ���� ��쿡�� ������.
//	if (n % 6 != 0)
//		ret = min(ret, 1 + Solve(n - 1));
//
//	return dp[n] = ret;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	memset(dp, -1, sizeof(dp));
//
//	printf("%d\n", Solve(n));
//}