//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> cards;
//	for (int i = 0; i < n; i++)
//	{
//		int k = 0;
//		cin >> k;
//		if (k <= m - 2)
//			cards.push_back(k);
//	}
//	int max = 0;
//	for (int i = 0; i < cards.size() - 2; i++)
//	{
//		for (int j = i + 1; j < cards.size() - 1; j++)
//		{
//			for (int k = j + 1; k < cards.size(); k++)
//			{
//				int a = cards[i] + cards[j] + cards[k];
//				if (a <= m && a > max)
//					max = a;
//			}
//		}
//	}
//	cout << max;
//
//	return 0;
//}