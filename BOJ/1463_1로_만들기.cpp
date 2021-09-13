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
//	// 2 또는 3으로 나누어 떨어질 경우 둘 중 어느 것으로 나누는 게 좋을지 알 수 없으나
//	// 어느 쪽이든 1을 빼는 것 보다는 나을 것이므로 1을 빼는 선택은 2와 3 둘 중 어느 것으로도 나눌 수 없는 경우에만 따진다.
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