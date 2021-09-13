//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	priority_queue<int> pq;
//
//	int x;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		if (x == 0)
//		{
//			if (pq.empty())
//			{
//				cout << 0 << endl;
//			}
//			else
//			{
//				cout << pq.top() << endl;
//				pq.pop();
//			}
//		}
//		else
//		{
//			pq.push(x);
//		}
//	}
//
//	return 0;
//}