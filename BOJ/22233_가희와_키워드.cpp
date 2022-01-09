//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <stdio.h>
//#include <map>
//#include <string.h>
//
//using namespace std;
//
//int main()
//{
//	//ios::sync_with_stdio(0);
//	//cin.tie(0);
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	map<string, int> dict;
//
//	int n, m;
//	//scanf("%d%d", &n, &n);
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		char c[11];
//		//scanf("%s", c);
//		cin >> c;
//		dict.emplace(c, 1);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		char c[110];
//		//scanf("%s", c);
//		cin >> c;
//
//		int removed = 0;
//
//		char* token = strtok(c, ",");
//
//		while (token != NULL)
//		{
//			if (dict.find(token) != dict.end() && dict[token] == 1)
//			{
//				removed++;
//				dict[token] = 0;
//			}
//
//			token = strtok(NULL, ",");
//		}
//
//		n -= removed;
//		//printf("%d\n", n);
//		cout << n << "\n";
//	}
//
//	return 0;
//}