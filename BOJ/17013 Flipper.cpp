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

	string s;
	cin >> s;
	bool horizontalFlip = false;
	bool verticalFlip = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'H')
			horizontalFlip = !horizontalFlip;
		else
			verticalFlip = !verticalFlip;
	}

	int grid[2][2] = { {1, 2}, {3, 4} };
	if (horizontalFlip)
	{
		swap(grid[0][0], grid[1][0]);
		swap(grid[0][1], grid[1][1]);
	}
	if (verticalFlip)
	{
		swap(grid[0][0], grid[0][1]);
		swap(grid[1][0], grid[1][1]);
	}

	cout << grid[0][0] << " " << grid[0][1] << endl;
	cout << grid[1][0] << " " << grid[1][1] << endl;

	return 0;
}