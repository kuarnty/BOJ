//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int t;
//	cin >> t;
//
//	for (int i = 0; i < t; i++)
//	{
//		int c, v;
//		cin >> c >> v;
//
//		vector<vector<int>> p;
//
//		for (int j = 0; j < v; j++)
//		{
//			vector<int> temp;
//			for (int k = 0; k < c; k++)
//			{
//				int cn;
//				cin >> cn;
//				temp.push_back(cn - 1);
//			}
//			p.push_back(temp);
//		}
//
//		vector<int> resultA(c);
//		for (int j = 0; j < v; j++)
//		{
//			resultA[p[j][0]]++;
//		}
//
//		int half = v / 2;
//		bool elected = false;
//		for (int j = 0; j < c; j++)
//		{
//			if (resultA[j] > half)
//			{
//				cout << j + 1 << " " << 1 << endl;
//				elected = true;
//				break;
//			}
//		}
//		if (!elected)
//		{
//			int max = 0;
//			int c1;
//			for (int j = 0; j < c; j++)
//			{
//				if (resultA[j] >=max)
//				{
//					max = resultA[j];
//					c1 = j;
//				}
//			}
//			max = 0;
//			int c2;
//			for (int j = 0; j < c; j++)
//			{
//				if (j != c1)
//				{
//					if (resultA[j] >= max)
//					{
//						max = resultA[j];
//						c2 = j;
//					}
//				}
//			}
//
//			vector<int> resultB(2);
//			for (int j = 0; j < v; j++)
//			{
//				for (int k = 0; k < c; k++)
//				{
//					if (p[j][k] == c1)
//					{
//						resultB[0]++;
//						break;
//					}
//					else if (p[j][k] == c2)
//					{
//						resultB[1]++;
//						break;
//					}
//				}
//			}
//
//			int winner = resultB[0] > resultB[1] ? c1 : c2;
//			cout << winner + 1 << " " << 2 << endl;
//		}
//	}
//
//	return 0;
//}