//unsolved

//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		v[i] = a;
//	}
//
//	vector<queue<int>> subSequences;
//
//	for (int i = 0; i < n; i++)
//	{
//		bool pushed = false;
//		for (int j = 0; j < subSequences.size(); j++)
//		{
//			if (subSequences[j].back() < v[i])
//			{
//				subSequences[j].push(v[i]);
//				pushed = true;
//			}
//		}
//		if (!pushed)
//		{
//			queue<int> q;
//			q.push(v[i]);
//			subSequences.push_back(q);
//		}
//	}
//
//	int max = 1;
//	//int maxIndex = 0;
//	for (int i = 0; i < subSequences.size(); i++)
//	{
//		if (subSequences[i].size() > max)
//		{
//			//maxIndex = i;
//			max = subSequences[i].size();
//		}
//	}
//
//	//while (!subSequences[maxIndex].empty())
//	//{
//	//	cout << subSequences[maxIndex].front() << ' ';
//	//	subSequences[maxIndex].pop();
//	//}
//	//cout << '\n';
//	cout << max;
//
//	return 0;
//}