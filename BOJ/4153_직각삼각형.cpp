//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	while (true)
//	{
//		cin >> a >> b >> c;
//		if (a == 0 && b == 0 && c == 0)
//			break;
//
//		if (a >= b && a >= c)
//		{
//			if (a * a == b * b + c * c)
//			{
//				cout << "right" << endl;
//			}
//			else
//			{
//				cout << "wrong" << endl;
//			}
//		}
//		else if (b >= a && b >= c)
//		{
//			if (b * b == a * a + c * c)
//			{
//				cout << "right" << endl;
//			}
//			else
//			{
//				cout << "wrong" << endl;
//			}
//		}
//		else if (c >= b && c >= a)
//		{
//			if (c * c == b * b + a * a)
//			{
//				cout << "right" << endl;
//			}
//			else
//			{
//				cout << "wrong" << endl;
//			}
//		}
//	}
//
//	return 0;
//}