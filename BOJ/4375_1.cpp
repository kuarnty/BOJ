//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//
//	while (cin >> n)
//	{
//		int m = 1;
//		int c = 1;
//
//		while (true)
//		{
//			if (m % n == 0)
//			{
//				cout << c << endl;
//				break;
//			}
//
//			m = (m * 10 + 1) % n;
//			// n으로 나눠지는 값은 10배를 해도 나눠지기 때문에 % 연산을 미리 해 주어 없애 준다.
//			// 그러면 반복적으로 나눠져야 하는 값 즉, 나머지에 대해서만 % 연산을 하게 되므로 큰 수에 대한 % 연산을 하지 않아도 된다.
//			// ex)	11은 3으로 나누어 떨어지지 않는데, 이때 몫은 9, 나머지는 2이다. 몫인 9는 10배를 하더라도 90으로 어차피 3의 배수이므로 연산할 필요가 없고, % 연산으로 미리 없애 준다.
//			//		나머지 값인 2를 10배 하고 일의자리 수 1을 더해 주면 이 값은 3으로 나누어떨어지는 것이 자명한 90을 제외한, 3으로 나누어떨어지는지 확인해야 하는 값이 된다.
//
//			c++;
//		}
//	}
//
//	return 0;
//}