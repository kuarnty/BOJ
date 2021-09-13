//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//static int m, n;
//
//struct Point
//{
//	int x;
//	int y;
//};
//
//int map[1000][1000] = { -1 };
//
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0 , -1 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	queue<Point> q;
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> map[i][j];
//			if (map[i][j] == 1)
//				q.push(Point{ i, j });
//		}
//	}
//
//	if (q.size() == m * n)
//	{
//		cout << 0;
//		return 0;
//	}
//
//	int day = 1;
//
//	while (!q.empty())
//	{
//		int x = q.front().x;
//		int y = q.front().y;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//
//			if (xx >= 0 && yy >= 0 && xx < m && yy < n && map[xx][yy] == 0)
//			{
//				map[xx][yy] = map[x][y] + 1;
//				q.push(Point{ xx, yy });
//			}
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] == 0)
//			{
//				cout << -1;
//				return 0;
//			}
//
//			if (map[i][j] > day)
//				day = map[i][j];
//		}
//	}
//
//	cout << day - 1;
//
//	return 0;
//}