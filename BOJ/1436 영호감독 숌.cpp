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

	int num = 666;
	int n;
	cin >> n;
	for (int cnt = 1; cnt < n;)
	{
		int temp = ++num;
		bool isEnd = false;
		int sixCnt = 0;
		while (temp > 0)
		{
			if (temp % 10 == 6)
				++sixCnt;
			else
				sixCnt = 0;
			if (sixCnt >= 3)
			{
				isEnd = true;
				break;
			}
			temp /= 10;
		}
		if (isEnd)
			++cnt;
	}

	cout << num;

	return 0;
}