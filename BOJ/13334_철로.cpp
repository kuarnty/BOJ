#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> list(n);
	for (int i = 0; i < n; i++)
	{
		int home, office;
		cin >> home >> office;
		list[i].first = MIN(home, office);
		list[i].second = MAX(home, office);
	}

	sort(list.begin(), list.end(), cmp);

	priority_queue<int> pq;

	int d;
	cin >> d;

	int max = 0;
	int left = list[0].first;
	int right = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (list[i].second - list[i].first > d)
			continue;
		else
		{
			left = list[i].first;
			if (right - left > d)
				right = left + d;
			pq.push(list[i].second);

			while (!pq.empty() && right < pq.top())
				pq.pop();

			max = MAX(max, pq.size());
		}
	}

	cout << max;

	return 0;
}