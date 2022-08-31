#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

int map[100][100];
unsigned long long result[100][100];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	result[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int length = map[i][j];
			if (length == 0)
				continue;

			if (i + length < n)
				result[i + length][j] += result[i][j];
			if (j + length < n)
				result[i][j + length] += result[i][j];
		}
	}

	cout << result[n - 1][n - 1];

	return 0;
}