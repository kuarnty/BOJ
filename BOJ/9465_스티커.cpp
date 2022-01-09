//#include <iostream>
//#include <vector>
//
//#define MAX(A, B) A > B ? A : B
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int t;
//	cin >> t;
//	while(t--)
//	{
//		int n;
//		cin >> n;
//
//		vector<int[2]> v(n);	
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				int value;
//				cin >> value;
//				v[j][i] = value;
//			}
//		}
//
//		if (n == 1)
//		{
//			int r = MAX(v[0][0], v[0][1]);
//			cout << r << '\n';
//			continue;
//		}
//		else if (n == 2)
//		{
//			int r = MAX(v[0][0] + v[1][1], v[0][1] + v[1][0]);
//			cout << r << '\n';
//			continue;
//		}
//
//		v[1][0] += v[0][1];
//		v[1][1] += v[0][0];
//		for (int i = 2; i < n; i++)
//		{
//			v[i][0] += MAX(v[i - 1][1], v[i - 2][1]);
//			v[i][1] += MAX(v[i - 1][0], v[i - 2][0]);
//		}
//		int r = MAX(v[n - 1][0], v[n - 1][1]);
//		cout << r << '\n';
//	}
//
//	return 0;
//}