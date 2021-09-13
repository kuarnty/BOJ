//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	if (k < 0 || k>n)
//	{
//		cout << 0;
//	}
//	else
//	{
//		int nSubk = n - k;
//		int nFactorial = 1;
//		for (int i = 0; i < n; i++)
//		{
//			nFactorial *= i + 1;
//		}
//		int kFactorial = 1;
//		for (int i = 0; i < k; i++)
//		{
//			kFactorial *= i + 1;
//		}
//		int nSubkFactorial = 1;
//		for (int i = 0; i < nSubk; i++)
//		{
//			nSubkFactorial *= i + 1;
//		}
//
//		cout << nFactorial / (kFactorial * nSubkFactorial);
//	}
//
//	return 0;
//}