#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

#define BOARD_SIZE_MAX		100

#define UP					{ -1, 0 }
#define RIGHT				{ 0, 1 }
#define DOWN				{ 1, 0 }
#define LEFT				{ 0, -1 }

using namespace std;

bool snakes[BOARD_SIZE_MAX + 1][BOARD_SIZE_MAX + 1] = { false, };
bool apples[BOARD_SIZE_MAX + 1][BOARD_SIZE_MAX + 1] = { false, };
int boardSize = 0;

struct BodyBlock
{
	pair<int, int> block;
	pair<int, int> dir;
};

class Snake
{
private:
	vector<BodyBlock> body;
	pair<int, int> direction;

private:
	bool isCollision()
	{
		pair<int, int> headBlock = body[0].block;
		if (headBlock.first < 1 || headBlock.first > boardSize
			|| headBlock.second < 1 || headBlock.second > boardSize
			|| snakes[headBlock.first][headBlock.second])
			return true;
		return false;
	}

	void eatApple()
	{
		pair<int, int> headBlock = body[0].block;
		if (apples[headBlock.first][headBlock.second])
			apples[headBlock.first][headBlock.second] = false;
		else
		{
			snakes[body.back().block.first][body.back().block.second] = false;
			body.pop_back();
		}
	}

public:

	Snake(int x, int y, pair<int, int> dir)
	{

		body.push_back({ { x, y }, dir });
	}

	bool move()
	{
		BodyBlock head = body[0];

		// insert head forward
		body.insert(body.begin(),
			{ { (head.block.first + head.dir.first), (head.block.second + head.dir.second) }, head.dir });

		// check collision of body or wall
		if (isCollision())
			return false;
		else
		{
			// increase snake length
			snakes[body[0].block.first][body[0].block.second] = true;
			// eat apple or remove tail
			eatApple();
		}
		return true;
	}

	void turn(char rotation)
	{
		BodyBlock& head = body[0];

		switch (rotation)
		{
		case 'L':
			head.dir = { -head.dir.second, head.dir.first };
			break;
		case 'D':
			head.dir = { head.dir.second, -head.dir.first };
			break;
		}
	}
};

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> boardSize;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		apples[x][y] = true;
	}

	int l;
	cin >> l;
	vector<pair<int, char>> rotations(l);
	for (int i = 0; i < l; i++)
		cin >> rotations[i].first >> rotations[i].second;

	Snake snake(1, 1, RIGHT);
	int time = 0;
	int rotationIdx = 0;
	while (true)
	{
		time++;
		if (!snake.move())
			break;
		else
		{
			if (rotationIdx < l && time == rotations[rotationIdx].first)
				snake.turn(rotations[rotationIdx++].second);
		}
	}

	cout << time;

	return 0;
}