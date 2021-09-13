//#include <iostream>
//
//using namespace std;
//
//int GCD(int a, int b)
//{
//	for (int i = b; i > 0; i--)
//	{
//		if ((a % i == 0) && (b % i == 0))
//			return i;
//	}
//}
//
//int LCM(int a, int b)
//{
//	int i = a;
//	while (true)
//	{
//		if ((i % a == 0) && (i % b == 0))
//		{
//			return i;
//		}
//		i++;
//	}
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	if (a < b)
//	{
//		int c = a;
//		a = b;
//		b = c;
//	}
//
//	// a>=b ภฮ ป๓ลย
//	cout << GCD(a, b) << endl << LCM(a, b);
//
//	return 0;
//}