#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int y;
	cin >> y;
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
			{
				y = 1;
			}
			else
				y = 0;
		}
		else
			y = 1;
	}
	else
		y = 0;

	cout << y;

	return 0;
}