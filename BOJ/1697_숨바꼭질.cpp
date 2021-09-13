//#define _CRT_SECURE_NO_WARNINGS
//#define MAX 100001
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//static bool visited[MAX] = { 0 };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//
//	if (n == k)
//	{
//		cout << 0;
//		return 0;
//	}
//
//	queue<int> q;
//	int depth = 0;
//
//	q.push(n);
//	visited[n] = true;
//
//	while (!q.empty())
//	{
//		int size = q.size();
//
//		for (int i = 0; i < size; i++)
//		{
//			int v = q.front();
//			q.pop();
//
//			if (v == k)
//			{
//				cout << depth;
//				return 0;
//			}
//			
//			if (v - 1 >= 0 && !visited[v - 1])
//			{
//				q.push(v - 1);
//				visited[v - 1] = true;
//			}
//			
//			if (v + 1 <= MAX && !visited[v + 1])
//			{
//				q.push(v + 1);
//				visited[v + 1] = true;
//			}
//
//			if (v * 2 <= MAX && !visited[v * 2])
//			{
//				q.push(v * 2);
//				visited[v * 2] = true;
//			}
//		}
//		depth++;
//	}
//
//	return 0;
//}