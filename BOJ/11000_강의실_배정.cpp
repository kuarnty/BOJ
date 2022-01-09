//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//struct Lecture
//{
//	int start;
//	int end;
//};
//
//struct compare
//{
//	bool operator()(const Lecture a, const Lecture b)
//	{
//		if (a.start == b.start)
//			return a.end > b.end;
//		else
//			return a.start > b.start;
//	}
//};
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	priority_queue<Lecture, vector<Lecture>, compare> pq;
//
//	for (int i = 0; i < n; i++)
//	{
//		int start, end;
//		cin >> start >> end;
//
//		pq.push({ start, end });
//	}
//
//	priority_queue<int, vector<int>, greater<int>> lectureRooms;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (lectureRooms.empty())
//		{
//			lectureRooms.push(pq.top().end);
//			pq.pop();
//		}
//		else
//		{
//			if (lectureRooms.top() <= pq.top().start)
//			{
//				lectureRooms.pop();
//				lectureRooms.push(pq.top().end);
//				pq.pop();
//			}
//			else
//			{
//				lectureRooms.push(pq.top().end);
//				pq.pop();
//			}
//		}
//	}
//
//	cout << lectureRooms.size();
//
//	return 0;
//}