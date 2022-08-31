#include <iostream>
#include <vector>

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))

using namespace std;

int result = 0;

vector<vector<int>> shift(vector<vector<int>> board, int dir)
{
	switch (dir)
	{
	case 0:
		for (int j = 0; j < board.size(); j++)
		{
			int index = -1;
			int value = -1;

			for (int i = 0; i < board.size(); i++)
			{
				if (board[i][j] == value)
				{
					board[i][j] = 0;
					board[index][j] = value * 2;
					result = MAX(result, board[index][j]);
					value = -1;
				}
				else
				{
					if (board[i][j] == 0)
						continue;
					value = board[i][j];
					index++;
					board[i][j] = 0;
					board[index][j] = value;
				}
				result = MAX(result, board[i][j]);
			}
		}
		break;

	case 1:
		for (int j = 0; j < board.size(); j++)
		{
			int index = board.size();
			int value = -1;

			for (int i = board.size() - 1; i >= 0; i--)
			{
				if (board[i][j] == value)
				{
					board[i][j] = 0;
					board[index][j] = value * 2;
					result = MAX(result, board[index][j]);
					value = -1;
				}
				else
				{
					if (board[i][j] == 0)
						continue;
					value = board[i][j];
					index--;
					board[i][j] = 0;
					board[index][j] = value;
				}
			}
		}
		break;

	case 2:
		for (int i = 0; i < board.size(); i++)
		{
			int index = board.size();
			int value = -1;

			for (int j = board.size() - 1; j >= 0; j--)
			{
				if (board[i][j] == value)
				{
					board[i][j] = 0;
					board[i][index] = value * 2;
					result = MAX(result, board[i][index]);
					value = -1;
				}
				else
				{
					if (board[i][j] == 0)
						continue;
					value = board[i][j];
					index--;
					board[i][j] = 0;
					board[i][index] = value;
				}
			}
		}
		break;

	case 3:
		for (int i = 0; i < board.size(); i++)
		{
			int index = -1;
			int value = -1;

			for (int j = 0; j < board.size(); j++)
			{
				if (board[i][j] == value)
				{
					board[i][j] = 0;
					board[i][index] = value * 2;
					result = MAX(result, board[i][index]);
					value = -1;
				}
				else
				{
					if (board[i][j] == 0)
						continue;
					value = board[i][j];
					index++;
					board[i][j] = 0;
					board[i][index] = value;
				}
			}
		}
		break;

	default:
		break;
	}

	return board;
}

void dfs(vector<vector<int>> board, int count)
{
	if (count == 5)
		return;

	for (int i = 0; i < 4; i++)
		dfs(shift(board, i), count + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> board;

	for (int i = 0; i < n; i++)
	{
		vector<int> t(n);
		for (int j = 0; j < n; j++)
		{
			cin >> t[j];
			result = MAX(result, t[j]);
		}
		board.push_back(t);
	}

	dfs(board, 0);

	cout << result;

	return 0;
}