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

bool comparePairII(const pair<int, int>& a, const pair<int, int>& b)
{
	return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p.begin(), p.end(), comparePairII);

	for (int i = 0; i < n; i++)
		cout << p[i].first << " " << p[i].second << endl;

	return 0;
}