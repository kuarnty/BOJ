#include <iostream>
#include <vector>

using namespace std;

int map[129][129];
int whiteCount = 0;
int blueCount = 0;

void Check(int x, int y, int n)
{
	int count = 0;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (map[i][j] == 1)
			{
				count++;
			} 
		}
	}

	if (count == 0)
	{
		whiteCount++;
	}
	else if (count == n * n)
	{
		blueCount++;
	}
	else
	{
		Check(x, y, n / 2);
		Check(x, y + n / 2, n / 2);
		Check(x + n / 2, y, n / 2);
		Check(x + n / 2, y + n / 2, n / 2);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	Check(0, 0, n);

	cout << whiteCount << endl << blueCount;

	return 0;
}