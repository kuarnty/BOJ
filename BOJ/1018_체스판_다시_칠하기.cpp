//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<char>> v;
//	int min = 32;
//	for (int i = 0; i < n; i++)
//	{
//		vector<char> vv;
//		char s[51];
//		cin >> s;
//		for (int j = 0; j < m; j++)
//		{
//			vv.push_back(s[j]);
//		}
//		v.push_back(vv);
//	}
//
//	for (int i = 0; i < n - 7; i++)
//	{
//		for (int j = 0; j < m - 7; j++)
//		{
//			char startColor;
//			startColor = v[i][j];
//			int count = 0;
//			// i+j�� ¦���̸� (i,j)�� ���� ��, Ȧ���̸� �ٸ� ��
//			for (int k = 0; k < 8; k++)
//			{
//				for (int l = 0; l < 8; l++)
//				{
//					// ���� ���̾�� ��
//					if ((k + l) % 2 == 0)
//					{
//						if (v[i + k][j + l] != startColor)
//							count++;
//					}
//					// �ٸ� ���̾�� ��
//					else
//					{
//						if (v[i + k][j + l] == startColor)
//							count++;
//					}
//				}
//			}
//			if (count > 32)
//				count = 64 - count;
//			if (count < min)
//				min = count;
//		}
//	}
//	cout << min;
//
//	return 0;
//}