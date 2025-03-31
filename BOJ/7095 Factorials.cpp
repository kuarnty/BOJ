#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cmath>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define MAX_NUM 150000

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	long double t = 0;
	for (int i = 1; floor(t) <= MAX_NUM; i++)
	{
		t += log10(i);
		if ((int)(t + 1e-6) == n - 1)
			v.push_back(i);
	}

	if (v.empty())
		cout << "NO" << endl;
	else
	{
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
	}

	return 0;
}