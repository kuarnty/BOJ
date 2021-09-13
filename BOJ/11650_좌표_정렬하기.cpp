//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Point
//{
//	int x;
//	int y;
//};
//
//bool cmp(Point p1, Point p2)
//{
//	return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Point> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].x >> v[i].y;
//	}
//
//	sort(v.begin(), v.end(), cmp);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].x << " " << v[i].y << "\n";
//	}
//
//	return 0;
//}
