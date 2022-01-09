//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define MIN(A, B) (A < B ? A : B)
//
//using namespace std;
//
//struct Cost
//{
//	int value;
//	int lastColor;
//};
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	// Red 0, Green 1, Blue 2
//	vector<vector<int>> v(n);
//
//	vector<vector<int>> r(n);
//	for (int i = 0; i < n; i++)
//	{
//		r[i] = vector<int>(3);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int cost;
//			cin >> cost;
//			v[i].push_back(cost);
//		}
//	}
//
//	r[0][0] = v[0][0];
//	r[0][1] = v[0][1];
//	r[0][2] = v[0][2];
//
//	for (int i = 1; i < n; i++)
//	{
//		r[i][0] = MIN(r[i - 1][1], r[i - 1][2]) + v[i][0];
//		r[i][1] = MIN(r[i - 1][0], r[i - 1][2]) + v[i][1];
//		r[i][2] = MIN(r[i - 1][1], r[i - 1][0]) + v[i][2];
//	}
//
//	cout << MIN(r[n - 1][0], (MIN(r[n - 1][1], r[n - 1][2])));
//
//	return 0;
//}