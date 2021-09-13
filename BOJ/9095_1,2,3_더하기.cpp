//#include <iostream>
//
//using namespace std;
//
//int cnt = 0;
//
//void calc(int sum, int goal)
//{
//	if (sum > goal)
//	{
//		return;
//	}
//	else if (sum == goal)
//	{
//		cnt++;
//		return;
//	}
//	else
//	{
//		for (int i = 1; i <= 3; i++)
//		{
//			calc(sum + i, goal);
//		}
//		return;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int t;
//	cin >> t;
//
//	int n;
//	for (int i = 0; i < t; i++)
//	{
//		cnt = 0;
//		cin >> n;
//		calc(0, n);
//		cout << cnt << endl;
//	}
//
//	return 0;
//}