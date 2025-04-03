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

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int cut = (int)floor((double)n * 0.15 + 0.5);
	int sum = 0;
	for (int i = cut; i < n - cut; i++)
		sum += v[i];
	cout << (int)floor((double)sum / (n - cut - cut) + 0.5);

	return 0;
}