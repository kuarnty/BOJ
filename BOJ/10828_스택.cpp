//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	stack<int> k;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		if (s == "pop")
//		{
//			if (k.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", k.top());
//				k.pop();
//			}
//		}
//		else if (s == "size")
//		{
//			printf("%d\n", k.size());
//		}
//		else if (s == "empty")
//		{
//			printf("%d\n", k.empty() ? 1 : 0);
//		}
//		else if (s == "top")
//		{
//			printf("%d\n", k.empty() ? -1 : k.top());
//		}
//		else // s== "push"
//		{
//			int m;
//			cin >> m;
//			k.push(m);
//		}
//	}
//}