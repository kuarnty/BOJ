//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	n = 1000 - n;
//
//	int c = 0;
//
//	while (n >= 1)
//	{
//		if (n >= 500)
//		{
//			n -= 500;
//			c++;
//		}
//		else if (n >= 100)
//		{
//			n -= 100;
//			c++;
//		}
//		else if (n >= 50)
//		{
//			n -= 50;
//			c++;
//		}
//		else if (n >= 10)
//		{
//			n -= 10;
//			c++;
//		}
//		else if (n >= 5)
//		{
//			n -= 5;
//			c++;
//		}
//		else
//		{
//			n -= 1;
//			c++;
//		}
//	}
//
//	int coins[6] = { 500, 100, 50, 10, 5, 1 };
//
//	for (int i = 0; i < 6; i++)
//	{
//		if (n >= coins[i])
//		{
//			int m = n / coins[i];
//			n -= coins[i] * m;
//			c += m;
//		}
//	}
//
//	cout << c;
//
//	return 0;
//}