#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

#define INT_MAX 2147483647

using namespace std;

int bit[5] = { 1, 2, 4, 8, 16 };

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			cout << 0;
		else if (i == 1)
			cout << 1;
		else
		{
			bool started = false;
			for (int j = 7; j >= 0; --j)
			{
				int result = i >> j & 1;
				if (!started && result == 0)
					continue;
				else if (!started && result != 0)
					started = true;
				cout << result;
			}
		}
	}

	return 0;
}