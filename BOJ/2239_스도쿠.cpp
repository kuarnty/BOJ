#include <iostream>

#define endl "\n"

using namespace std;

int board[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

bool dfs(int count)
{
	if (count == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		exit(0);
	}

	int x = count / 9;
	int y = count % 9;

	if (board[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
			{
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				board[x][y] = i;
				dfs(count + 1);

				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
				board[x][y] = 0;
			}
		}
	}
	else
	{
		dfs(count + 1);
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		char t[10];
		cin >> t;
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = t[j] - '0';
			int num = board[i][j];
			if (num != 0)
			{
				row[i][num] = true;
				col[j][num] = true;
				square[(i / 3) * 3 + (j / 3)][num] = true;
			}
		}
	}

	dfs(0);

	return 0;
}