//#include <iostream>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	queue<int> q;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		if (s == "pop")
//		{
//			if (q.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", q.front());
//				q.pop();
//			}
//		}
//		else if (s == "size")
//		{
//			printf("%d\n", q.size());
//		}
//		else if (s == "empty")
//		{
//			printf("%d\n", q.empty() ? 1 : 0);
//		}
//		else if (s == "front")
//		{
//			printf("%d\n", q.empty() ? -1 : q.front());
//		}
//		else if (s == "back")
//		{
//			printf("%d\n", q.empty() ? -1 : q.back());
//		}
//		else // s== "push"
//		{
//			int m;
//			cin >> m;
//			q.push(m);
//		}
//	}
//}