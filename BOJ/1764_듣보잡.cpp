//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
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
//
//	vector<string> listenlistenicantlisten(n);
//	vector<string> seeseeicantsee(m);
//	vector<string> listenseeicantlistensee;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> listenlistenicantlisten[i];
//	}
//	sort(listenlistenicantlisten.begin(), listenlistenicantlisten.end());
//	for (int i = 0; i < m; i++)
//	{
//		cin >> seeseeicantsee[i];
//	}
//	sort(seeseeicantsee.begin(), seeseeicantsee.end());
//
//	int l = n >= m ? n : m;
//
//	int c1 = 0, c2 = 0;
//
//	while (c1 < listenlistenicantlisten.size() && c2 < seeseeicantsee.size())
//	{
//		if (listenlistenicantlisten[c1] == seeseeicantsee[c2])
//		{
//			listenseeicantlistensee.push_back(listenlistenicantlisten[c1]);
//			c1++;
//			c2++;
//		}
//		else
//		{
//			listenlistenicantlisten[c1] < seeseeicantsee[c2] ? c1++ : c2++;
//		}
//	}
//
//	cout << listenseeicantlistensee.size() << "\n";
//
//	for (int i = 0; i < listenseeicantlistensee.size(); i++)
//	{
//		cout << listenseeicantlistensee[i] << "\n";
//	}
//
//	return 0;
//}