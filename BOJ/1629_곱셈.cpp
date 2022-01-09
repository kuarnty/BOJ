//#include <iostream>
//
//using namespace std;
//
//int calc(int b, int e, int c)
//{
//	if (e == 1)
//		return b % c;
//
//	long t = calc(b, e / 2, c);
//
//	t = (t * t) % c;
//
//	return e % 2 == 1 ? (t * b) % c : t;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	long a;
//	int b, c;
//	cin >> a >> b >> c;
//
//	cout << calc(a, b, c);
//
//	return 0;
//}