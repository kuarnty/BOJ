#include <iostream>
#include <math.h>
//strlen은 cstring에 있다 쓰레기같은거

#define INT_MAX 2147483647

using namespace std;

int colNum = 0;
int col[111111][11];
long long pos[11];

int N;
int K;

bool findCol(int point[11])
{
	for (int i = 0; i < colNum; i++)
	{
		if (col[i] == point)
			return true;
	}
	return false;
}

void CheckCollision(int point[11])
{
	for (int i = 0; i < 11; i++)
	{
		if (point[i] == 0 || point[i] == N - 1)
			pos[i]--;
		else
			pos[i] -= 2;

		if (point[i] > 0)
		{
			point[i]--;
			if (findCol(point))
			{
				pos[i]++;
			}
			point[i]++;
		}

		if (point[i] < N - 1)
		{
			point[i]++;
			if (findCol(point))
			{
				pos[i]++;
			}
			point[i]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 11; i++)
	{
		pos[i] = (N - 1) * pow(N, 10);
	}

	int point[11];

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cin >> point[j];
			point[j]--;
		}
		CheckCollision(point);
	}

	for (int i = 0; i < 11; i++)
	{
		cout << pos[i] << '\n';
	}

	return 0;
}