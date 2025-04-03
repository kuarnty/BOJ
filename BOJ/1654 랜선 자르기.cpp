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

	int k, n;
	cin >> k >> n;
	vector<int> lans(k);
	for (int i = 0; i < k; i++)
		cin >> lans[i];

	long long min = 1, max = INT_MAX;
	long long mid = (min + max) / 2;
	long long sum = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		//cout << "mid: " << mid << "\tmin/max: " << min << "/" << max << endl;
		sum = 0;
		for (int i = 0; i < lans.size(); i++)
			sum += lans[i] / mid;
		(sum >= n) ? (min = mid + 1) : (max = mid - 1);

	}

	//mid = (min + max) / 2;
	cout << max << endl;

	return 0;
}