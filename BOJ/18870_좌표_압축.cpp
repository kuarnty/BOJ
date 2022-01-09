//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	vector<int> v(n);
//	vector<int> orderedV;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v[i] = x;
//	}
//
//	orderedV = v;
//	sort(orderedV.begin(), orderedV.end());
//	orderedV.erase(unique(orderedV.begin(), orderedV.end()), orderedV.end());
//
//	map<int, int> m;
//	for (int i = 0; i < orderedV.size(); i++)
//	{
//		m.insert(pair<int, int>(orderedV[i], i));
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << m[v[i]] << " ";
//	}
//
//	return 0;
//}