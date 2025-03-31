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

	int t, n, m;
	cin >> t;
	cin >> n;
	vector<long long> preSumA(n + 1);
	preSumA[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> preSumA[i];
		preSumA[i] += preSumA[i - 1];
	}
	cin >> m;
	vector<long long> preSumB(m + 1);
	preSumB[0] = 0;
	for (int i = 1; i < m + 1; i++)
	{
		cin >> preSumB[i];
		preSumB[i] += preSumB[i - 1];
	}

	vector<long long> subSumA, subSumB;
	for (int i = 1; i < n + 1; i++)
		for (int j = i; j < n + 1; j++)
			subSumA.push_back(preSumA[j] - preSumA[i - 1]);
	for (int i = 1; i < m + 1; i++)
		for (int j = i; j < m + 1; j++)
			subSumB.push_back(preSumB[j] - preSumB[i - 1]);

	sort(subSumA.begin(), subSumA.end());
	sort(subSumB.begin(), subSumB.end());

	long long cnt = 0;

	for (int i = 0; i < subSumA.size(); i++)
	{
		long long val = t - subSumA[i];
		auto range = equal_range(subSumB.begin(), subSumB.end(), val);
		cnt += range.second - range.first;
	}

	cout << cnt << endl;

	return 0;
}