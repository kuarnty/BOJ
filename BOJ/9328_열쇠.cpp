#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define endl			'\n'

#define UPPER_OFFSET			65
#define LOWER_OFFSET			97
#define ALPHABET_NUMBER			26
#define MAX_HEIGHT				100
#define MAX_WIDTH				100

using namespace std;

char map[MAX_HEIGHT][MAX_WIDTH];
bool visited[MAX_HEIGHT][MAX_WIDTH];
bool keys[ALPHABET_NUMBER];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int h, w;
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			cin >> map[i];

		// initialize
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				visited[i][j] = false;
		for (int i = 0; i < ALPHABET_NUMBER; i++)
			keys[i] = false;

		string keyString;
		cin >> keyString;

		if (keyString != "0")
			for (int i = 0; i < keyString.length(); i++)
				keys[keyString[i] - LOWER_OFFSET] = true;

		queue<pair<int, int>> q;
		vector<queue<pair<int, int>>> doors(ALPHABET_NUMBER);
		int keyFound = -1;

		int ret = 0;

		// find entrances
		// vertical
		for (int i = 0; i < h; i++)
		{
			if (map[i][0] != '*')
				q.push({ i, 0 });
			if (map[i][w - 1] != '*')
				q.push({ i, w - 1 });
		}
		// horizontal
		for (int i = 1; i < w - 1; i++)
		{
			if (map[0][i] != '*')
				q.push({ 0, i });
			if (map[h - 1][i] != '*')
				q.push({ h - 1, i });
		}

		while (!q.empty())
		{
			pair<int, int> curPos = q.front();
			q.pop();
			int x = curPos.first;
			int y = curPos.second;
			if (visited[x][y])
				continue;

			char& cur = map[x][y];
			visited[x][y] = true;

			if (cur == '$')
			{
				ret++;
				//cur = '.';
			}
			else if (cur == '.')
			{
				;
			}
			// lowercase: key
			else if (LOWER_OFFSET <= cur && cur < LOWER_OFFSET + ALPHABET_NUMBER)
			{
				if (keys[cur - LOWER_OFFSET] != true)
				{
					keys[cur - LOWER_OFFSET] = true;
					keyFound = (cur - LOWER_OFFSET);
				}
				// cur = '.';
			}
			// uppercase: locked door
			else
			{
				// has the key
				if (keys[cur - UPPER_OFFSET] == true)
				{
					//cur = '.';
					;
				}
				else
				{
					// if the door locked without key
					doors[cur - UPPER_OFFSET].push({ x,y });
					// don't push adjs
					continue;
				}
			}

			// push adjs
			// up
			if (x > 0 && !visited[x - 1][y] && map[x - 1][y] != '*')
				q.push({ x - 1, y });
			// down
			if (x < h - 1 && !visited[x + 1][y] && map[x + 1][y] != '*')
				q.push({ x + 1, y });
			// left
			if (y > 0 && !visited[x][y - 1] && map[x][y - 1] != '*')
				q.push({ x, y - 1 });
			// right
			if (y < w - 1 && !visited[x][y + 1] && map[x][y + 1] != '*')
				q.push({ x, y + 1 });

			// check doors which is able to open with a key just found
			if (keyFound != -1)
			{
				while (!doors[keyFound].empty())
				{
					q.push(doors[keyFound].front());
					map[doors[keyFound].front().first][doors[keyFound].front().second] = '.';
					visited[doors[keyFound].front().first][doors[keyFound].front().second] = false;
					doors[keyFound].pop();
				}
			}
			keyFound = -1;
		}

		cout << ret << endl;
	}
	return 0;
}