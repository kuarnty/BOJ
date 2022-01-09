//unsolved
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct Problem
//{
//	unsigned int deadLine;
//	unsigned int cupRamyeon;
//};
//
//bool compare(Problem& a, Problem& b)
//{
//	return a.deadLine > b.deadLine;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	vector<Problem> v;
//
//	for (int i = 0; i < n; i++)
//	{
//		int deadLine, cupRamyeon;
//		cin >> deadLine >> cupRamyeon;
//
//		Problem p;
//		p.deadLine = deadLine;
//		p.cupRamyeon = cupRamyeon;
//
//		v.push_back(p);
//	}
//
//	sort(v.begin(), v.end(), compare);
//
//	priority_queue<int> pq;
//
//	unsigned int result = 0;
//
//	for (int i = n, j = 0; i >= 1; i--)
//	{
//		while (j < n)
//		{
//			if (i == v[j].deadLine)
//			{
//
//			}
//			j++;
//		}
//	}
//
//
//	sort(q.front(), q.back());
//
//	cout << q.front();
//
//
//	return 0;
//}