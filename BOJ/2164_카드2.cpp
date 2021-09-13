//#include <iostream>
//#include <queue>
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
//		q.push(i+1);
//	}
//	while (q.size() > 1)
//	{
//		q.pop();
//		if (q.size() == 1)
//			break;
//		q.push(q.front());
//		q.pop();
//	}
//	cout << q.front();
//
//	return 0;
//}