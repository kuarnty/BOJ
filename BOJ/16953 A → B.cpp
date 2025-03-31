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

using namespace std;

void bfs()
{
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	queue<pair<long long, int>> q;

	q.push({ a, 1 });
	while (!q.empty())
	{
		long long num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == b)
		{
			cout << cnt;
			return 0;
		}
		if (num * 2 <= b)
			q.push({ num * 2, cnt + 1 });
		if (num * 10 + 1 <= b)
			q.push({ num * 10 + 1, cnt + 1 });
	}
	cout << -1;

	return 0;
}