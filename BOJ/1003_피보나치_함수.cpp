//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//
////int fibonacci(int n)
////{
////	if (n == 0)
////	{
////		count0++;
////		return 0;
////	}
////	else if (n == 1)
////	{
////		count1++;
////		return 1;
////	}
////	else
////	{
////		return fibonacci(n - 1) + fibonacci(n - 2);
////	}
////}
//
//int main()
//{
//	int t;
//	cin >> t;
//	int data[41] = { 0, 1 };
//	for (int i = 2; i < 41; i++)
//	{
//		data[i] = data[i - 2] + data[i - 1];
//	}
//
//	for (int i = 0; i < t; i++)
//	{
//		int n;
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			printf("%d %d\n", 1, 0);
//		}
//		else
//		{
//			printf("%d %d\n", data[n - 1], data[n]);
//		}
//
//	}
//
//	return 0;
//}