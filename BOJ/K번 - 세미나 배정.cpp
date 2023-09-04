#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;
vector<int> a;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int aa = 0;
		cin >> aa;
		a.push_back(aa - 1);
	}

	sort(a.begin(), a.end());

	long long room = a[0];
	if (a[0] < t - 1)
		room = t - 1;
	pq.push(room);

	for (int s = 1; s < n; s++)
	{
		if (pq.top() < a[s])
		{
			room = pq.top();
			pq.pop();

			if (room + t <= a[s])
				room = a[s];
			else
				room += t;

			pq.push(room);
		}
		else
		{
			room = a[s];
			if (a[s] < t - 1)
				room = t - 1;
			pq.push(room);
		}
	}

	cout << pq.size();

	return 0;
}