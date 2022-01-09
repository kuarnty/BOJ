//#include <iostream>
//#include <vector>
//#include <cstring>
//
//#define MAX(a, b) a > b ? a : b
//
//using namespace std;
//
//int s[1002][1002] = { 0 };
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	char a[1002];
//	char b[1002];
//
//	cin >> a >> b;
//
//	int lengthA = strlen(a);
//	int lengthB = strlen(b);
//
//	for (int i = 1; i <= lengthA; i++)
//	{
//		for (int j = 1; j <= lengthB; j++)
//		{
//			s[i][j] = (a[i - 1] == b[j - 1]) ? (s[i - 1][j - 1] + 1) : MAX(s[i - 1][j], s[i][j - 1]);
//		}
//	}
//
//	cout << s[lengthA][lengthB];
//
//	return 0;
//}