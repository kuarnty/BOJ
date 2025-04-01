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

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		int sum = i;
		int num = i;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum == n)
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}