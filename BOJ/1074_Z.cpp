//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int main()
//{
//	int n, r, c;
//	cin >> n >> r >> c;
//	int count = 0;
//
//	while (n > 0)
//	{
//		int quarter = pow(2, n - 1) * pow(2, n - 1);
//		int half = pow(2, n) / 2;
//		if (r < half && c < half)
//		{
//			count += quarter * 0;
//		}
//		else if (r < half && c >= half)
//		{
//			c -= half;
//			count += quarter * 1;
//		}
//		else if (r >= half && c < half)
//		{
//			r -= half;
//			count += quarter * 2;
//		}
//		else if (r >= half && c >= half)
//		{
//			r -= half;
//			c -= half;
//			count += quarter * 3;
//		}
//
//		n--;
//	}
//
//	cout << count;
//
//	return 0;
//}