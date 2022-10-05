#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl			'\n'

using namespace std;

#define ii pair<int, int>

long long p[32];

void process(long long int left, vector<ii>& list, int current)
{
	if (left == 1)
		list.emplace_back(current, 0);
	else if (left % 2 == 0)
		process(left / 2, list, ++current);
	else
	{
		int exp = 20;
		while (p[exp] > left)
			exp--;

		if (left - p[exp] == 0)
			list.emplace_back(current, exp);
		else
		{
			list.emplace_back(current, exp);
			process(left - p[exp], list, current);
		}
	}
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < 32; i++)
		p[i] = pow(3, i);

	vector<ii>* ans = new vector<ii>[n];

	long long a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		process(a, ans[i], 0);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i].size() << endl;

		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j].first << ' ' << ans[i][j].second << endl;
	}

	delete[] ans;

	return 0;
}