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
	int cnt5 = 0;
	for (int i = 5; i <= n; i++)
	{
		int temp = i;
		while ((temp > 0) && (temp % 5 == 0))
		{
			temp /= 5;
			cnt5++;
		}
	}

	cout << cnt5;

	return 0;
}