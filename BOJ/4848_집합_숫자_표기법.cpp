//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<string> v;
//	v.push_back("{}");
//
//	for (int i = 1; i < 16; i++)
//	{
//		v.push_back("{");
//		for (int j = 0; j < i; j++)
//		{
//			if (j != 0)
//			{
//				v[i] += ",";
//			}
//			v[i] += v[j];
//		}
//		v[i] += "}";
//	}
//
//	//for (int i = 0; i < 16; i++)
//	//{
//	//	cout << v[i] << endl;
//	//}
//
//	int n;
//	string s1, s2;
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s1 >> s2;
//		int a = -1;
//		int b = -1;
//		for (int i = 0; i < 16; i++)
//		{
//			if (a == -1 && s1 == v[i])
//				a = i;
//			if (b == -1 && s2 == v[i])
//				b = i;
//
//			if (a != -1 && b != -1)
//			{
//				break;
//			}
//		}
//		cout << v[a + b] << endl;
//	}
//
//	return 0;
//}