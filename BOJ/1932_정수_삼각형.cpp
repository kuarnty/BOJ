//#include <iostream>
//#include <queue>
//
//#define MAX(A, B) A > B ? A : B
//
//using namespace std;
//
//int arr[500][500];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	queue<int> q;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < i+1; j++)
//		{
//			int t;
//			cin >> t;
//			arr[i][j] = t;
//		}
//	}
//
//	q.push(arr[0][0]);
//	for (int i = 1; i < n; i++)
//	{
//		int size = q.size();
//		q.push(q.front() + arr[i][0]);
//		for (int j = 1; j < size; j++)
//		{
//			int t = q.front();
//			q.pop();
//			int m = arr[i][j];
//			m += MAX(t, q.front());
//			q.push(m);
//		}
//		q.push(q.front() +arr[i][i]);
//		q.pop();
//	}
//
//	int max = 0;
//	while (!q.empty())
//	{
//		if (q.front() > max)
//			max = q.front();
//		q.pop();
//	}
//
//	cout << max;
//
//	return 0;
//}