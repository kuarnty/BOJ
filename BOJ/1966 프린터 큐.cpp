#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include <queue>
#include <stack>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		queue<int> docs;
		priority_queue<int> priorities;
		for (int i = 0; i < n; i++)
		{
			int doc;
			cin >> doc;
			priorities.push(doc);
			docs.push(doc);
		}

		int cnt = 0;
		int pos = m;
		while (true)
		{
			if (docs.front() >= priorities.top())
			{
				++cnt;
				if (pos == 0)
					break;
				else
				{
					docs.pop();
					priorities.pop();
					--pos;
				}
			}
			else
			{
				docs.push(docs.front());
				docs.pop();
				--pos;
				if (pos < 0)
					pos = docs.size() - 1;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}