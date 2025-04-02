#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

	int k;
	cin >> k;

	vector<int> v;

	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;

		if (n == 0)
			v.pop_back();
		else
			v.push_back(n);
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	cout << sum;

	return 0;
}