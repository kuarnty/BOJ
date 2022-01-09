//#include <iostream>
//
//using namespace std;
//
//const int MAX = 9;
//
//int n, m;
//
//int arr[MAX] = { 0 };
//
//// num: 선택할 수 있는 최솟값, cnt: 수열의 몇 번째 수를 구하는지
//void dfs(int num, int cnt)
//{
//	if (cnt == m)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = num; i <= n; i++)
//	{
//		arr[cnt] = i;
//		dfs(i + 1, cnt + 1);
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	cin >> n >> m;
//	dfs(1, 0);
//
//	return 0;
//}