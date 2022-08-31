#include <iostream>

#define MAXVALUE(a, b) a > b ? a : b

int result[101][100001] = { 0 };
int items[101][2];

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i][0] >> items[i][1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// can't
			if (j < items[i][0])
			{
				result[i][j] = result[i - 1][j];
			}
			// can
			else
			{
				result[i][j] = MAXVALUE(
					result[i - 1][j - items[i][0]] + items[i][1],	// do
					result[i - 1][j]);								// don't
			}
		}
	}

	cout << result[n][k];

	return 0;
}