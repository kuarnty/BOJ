//#include <iostream>
//
//using namespace std;
//
//int mat[1024][1024];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int t;
//			cin >> t;
//			mat[i][j] = t;
//			if (j >= 1)
//			{
//				mat[i][j] += mat[i][j - 1];
//			}
//		}
//		if (i >= 1)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				mat[i][j] += mat[i - 1][j];
//			}
//		}
//	}
//
//	while (m--)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		x1--; y1--; x2--; y2--;
//
//		int result = mat[x2][y2];
//		if (x1 != 0 || y1 != 0)
//		{
//			if (x1 != 0)
//				result -= mat[x1 - 1][y2];
//			if (y1 != 0)
//				result -= mat[x2][y1 - 1];
//			if (x1 != 0 && y1 != 0)
//				result += mat[x1 - 1][y1 - 1];
//		}
//		cout << result << '\n';
//	}
//
//	return 0;
//}