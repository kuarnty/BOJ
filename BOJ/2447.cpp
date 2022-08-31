#include <iostream>
#include <cmath>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

#pragma region MOOJISUNG

bool map[6561][6561] = { false };
// bool mapmap[6561][6561] = { true };

void star(int count, int x, int y, bool colour)
{
	if (!colour)
	{
		int length = pow(3, count - 1);
		for (int i = x; i < x + length; i++)
		{
			for (int j = y; j < y + length; j++)
			{
				map[i][j] = false;
			}
		}
	}
	else
	{
		if (count == 0)
		{
			map[x][y] = colour;
		}
		else
		{
			int length = pow(3, count - 1);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					star(count - 1, x + i * length, y + j * length, (i != 1 || j != 1));
				}
			}
		}
	}
}

#pragma endregion

#pragma region YOUJISUNG

void starstarstar(int length, int x, int y)
{
	if (((x / length) % 3 == 1) && ((y / length) % 3 == 1))
		cout << " ";
	else if (length == 1)
		cout << "*";
	else
		starstarstar(length / 3, x, y);
}

#pragma endregion

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	int length = n;
	
	// MOOJISUNG/////////////////////////////////////////////////////////////////////////////////////////////
	// from here

	int count = 0;
	while (n != 1)
	{
		n /= 3;
		count++;
	}

	star(count, 0, 0, true);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (map[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	// to here

	/////////////////////////////////////////////////////////////////

	// YOUJISUNG/////////////////////////////////////////////////////
	// from here

	int lengthlengthlength = length / 3;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			starstarstar(lengthlengthlength, i, j);
		}
		cout << "\n";
	}

	// to here
	/////////////////////////////////////////////////////////////////
	return 0;
}
