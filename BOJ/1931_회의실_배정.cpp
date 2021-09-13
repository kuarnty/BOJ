//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Time
//{
//	int begin;
//	int end;
//};
//
//bool cmp(Time t1, Time t2)
//{
//	if (t1.end != t2.end)
//	{
//		return t1.end < t2.end;
//	}
//	else
//	{
//		return t1.begin < t2.begin;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	vector<Time> v(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[i] = { a,b };
//	}
//
//	sort(v.begin(), v.end(), cmp);
//
//	int count = 1;
//	int time = v[0].end;
//
//	for (int i = 1; i < n; i++)
//	{
//		if (v[i].begin >= time)
//		{
//			count++;
//			time = v[i].end;
//		}
//		else
//			continue;
//	}
//
//	cout << count;
//
//	return 0;
//}