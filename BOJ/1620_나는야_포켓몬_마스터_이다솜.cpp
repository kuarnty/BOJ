//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	vector<string> names(n+1);
//	map<string, int> mp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> names[i + 1];
//		mp.insert({ names[i + 1], i + 1 });
//	}
//
//	string s;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> s;
//		if ('A' <= s[0] && 'Z' >= s[0])
//		{
//			cout << mp[s] << "\n";
//		}
//		else
//		{
//			cout << names[stoi(s)] << "\n";
//		}
//	}
//
//	return 0;
//}