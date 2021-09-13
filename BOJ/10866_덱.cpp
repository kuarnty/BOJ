//#include <iostream>
//#include <deque>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	deque<int> q;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		if (s == "pop_front")
//		{
//			if (q.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", q.front());
//				q.pop_front();
//			}
//		}
//		else if (s == "pop_back")
//		{
//			if (q.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", q.back());
//				q.pop_back();
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
//		else if (s == "push_front")
//		{
//			int m;
//			cin >> m;
//			q.push_front(m);
//		}
//		else if (s == "push_back")
//		{
//			int m;
//			cin >> m;
//			q.push_back(m);
//		}
//	}
//}