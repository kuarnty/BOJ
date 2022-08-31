#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

// point
#define P pair<int, int>
// pair of two points
#define PP pair<P, P>

using namespace std;

int n, m;
vector<vector<char>> board;

// down, right, left, up
int dirList[4] = { -2, -1, 1, 2 };

// try to move to marbles
// and return whether succeed or failed
// or locations of red, blue marbles
PP shift(P Red, P Blue, int dir)
{
	// set amount to move with dir variable
	int down = 0, right = 0;
	switch (dir)
	{
		// down
	case -2:
		down = 1;
		break;
		// right
	case -1:
		right = 1;
		break;
		// left
	case 1:
		right = -1;
		break;
		// up
	case 2:
		down = -1;
		break;
	default:
		break;
	}

	// check if each marbles escaped
	bool redEscaped = false, blueEscaped = false;
	// not to be two marbles overlapped
	int redMoveDist = -1, blueMoveDist = -1;

	// move red
	P redNext = Red;
	do
	{
		Red.first = redNext.first;
		Red.second = redNext.second;
		redMoveDist++;

		redNext.first += down;
		redNext.second += right;

		if (board[redNext.first][redNext.second] == 'O')
		{
			Red.first = redNext.first;
			Red.second = redNext.second;
			redMoveDist++;
			redEscaped = true;
			break;
		}
	} while (board[redNext.first][redNext.second] != '#');

	// move blue
	P blueNext = Blue;
	do
	{
		Blue.first = blueNext.first;
		Blue.second = blueNext.second;
		blueMoveDist++;

		blueNext.first += down;
		blueNext.second += right;

		if (board[blueNext.first][blueNext.second] == 'O')
		{
			Blue.first = blueNext.first;
			Blue.second = blueNext.second;
			blueMoveDist++;
			blueEscaped = true;
			break;
		}
	} while (board[blueNext.first][blueNext.second] != '#');


	if (blueEscaped)
		// failed
		Red.first = -2;
	else if (redEscaped)
		Red.first = -1;
	else
		// if two moved locations overlapped,
		// then move backward a marble 1 unit which moved more (since this marble is blocked by another)
		if (Red.first == Blue.first && Red.second == Blue.second)
		{
			if (redMoveDist > blueMoveDist)
			{
				Red.first -= down;
				Red.second -= right;
			}
			else
			{
				Blue.first -= down;
				Blue.second -= right;
			}
		}

	return { Red, Blue };
}

int bfs(P Red, P Blue)
{
	int cnt = 1;

	queue<pair<PP, int>> q;
	q.push({ { Red, Blue }, 0 });

	while (cnt <= 10)
	{
		int curBoardNum = q.size();

		while (curBoardNum--)
		{
			P red = q.front().first.first;
			P blue = q.front().first.second;
			int lastDir = q.front().second;
			q.pop();

			for (int curDirInd = 0; curDirInd < 4; curDirInd++)
				if (lastDir != dirList[curDirInd] && lastDir != -dirList[curDirInd])
				{
					PP result = shift(red, blue, dirList[curDirInd]);
					P redNext = result.first;
					P blueNext = result.second;

					// succeed
					if (redNext.first == -1)
						return cnt;
					// failed
					else if (redNext.first == -2)
						continue;
					// moved and changed
					else if (red != redNext || blue != blueNext)
					{
						q.push({ { redNext, blueNext }, dirList[curDirInd] });

						/*cout << "Red at [" << redNext.first << "][" << redNext.second << "]" << endl;
						cout << "Blue at [" << blueNext.first << "][" << blueNext.second << "]" << endl;
						cout << "Count: " << cnt << endl << endl;*/
					}
				}
		}
		cnt++;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;

	pair<int, int> Red, Blue;

	for (int i = 0; i < n; i++)
	{
		board.push_back(vector<char>(m));
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = s[j];
			if (s[j] == 'R')
			{
				Red = { i, j };
				board[i][j] = '.';
			}
			else if (s[j] == 'B')
			{
				Blue = { i, j };
				board[i][j] = '.';
			}
		}
	}

	cout << bfs(Red, Blue);

	return 0;
}