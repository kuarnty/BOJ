#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// <mass, value>
pair<int, int> jewels[300000];
bool stolen[300000];
int bags[300000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> jewels[i].first >> jewels[i].second;

	for (int i = 0; i < k; i++)
		cin >> bags[i];

	sort(jewels, jewels + n);
	sort(bags, bags + k);

	priority_queue<int> pq;

	long long sum = 0;

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && jewels[j].first <= bags[i])
			pq.push(jewels[j++].second);

		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}