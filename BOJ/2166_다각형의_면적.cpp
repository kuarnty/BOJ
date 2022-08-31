#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
	}

	double area = 0;

	pair<int, int> init = v[0];

	pair<int, int> last;
	pair<int, int> cur;

	for (int i = 2; i < n; i++)
	{
		last = v[i - 1];
		cur = v[i];

		double  a, b, c, d;
		a = last.second - init.second;
		b = cur.first - init.first;
		c = last.first - init.first;
		d = cur.second - init.second;
		area += (((double)(last.second - init.second) * (double)(cur.first - init.first)) - ((double)(last.first - init.first) * (double)(cur.second - init.second))) / 2;

	}

	cout.precision(1);
	cout << fixed;
	cout << abs(area);

	return 0;
}