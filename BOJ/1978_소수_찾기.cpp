//#include <iostream>
//
//using namespace std;
//
//bool Check(int m)
//{
//	if (m == 1)
//		return false;
//	else
//	{
//		int p = m / 2;
//		for (int i = 2; i <= p; i++)
//		{
//			if (m % i == 0)
//				return false;
//		}
//		return true;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int m;
//		cin >> m;
//		if (Check(m))
//			count++;
//	}
//
//	cout << count;
//
//	return 0;
//}