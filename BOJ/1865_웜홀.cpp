#include <iostream>
#include <vector>
#include <algorithm>
//strlen은 cstring에 있다 쓰레기같은거

#define MAXVALUE 5000000

using namespace std;

struct Edge
{
	int startVertex;
	int endVertex;
	int weight;
};

int adj[501][501];
int dist[501];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TC;
	cin >> TC;

	while (TC--)
	{
		int N, M, W;
		cin >> N >> M >> W;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				adj[i][j] = MAXVALUE;
			}
		}
		for (int i = 0; i < M; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;

			// 도로 추가
			// 도로가 여러개일 수 있음. 최솟값만 추가하자! 왜? -> 음수 사이클만 판정하면 되니까!
			if (adj[S][E] > T)
			{
				adj[S][E] = T;
				adj[E][S] = T;
			}
		}
		for (int i = 0; i < W; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			// 웜홀 추가
			// 웜홀은 도로보다 값이 작을 수 밖에 없으므로 그냥 추가해도 됨
			adj[S][E] = -T;
		}

		for (int i = 1; i <= N; i++)
		{
			dist[i] = MAXVALUE;
		}
		// 임의의 sourceId 1
		dist[1] = 0;

		int nodeCount = N;
		while (nodeCount--)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					if (adj[i][j] != MAXVALUE)
					{
						if (dist[j] > dist[i] + adj[i][j])
							dist[j] = dist[i] + adj[i][j];
					}
				}
			}
		}

		bool negativeCycle = false;
		for (int i = 1; i <= N; i++)
		{
			if (negativeCycle)
				break;
			for (int j = 1; j <= N; j++)
			{
				if (negativeCycle)
					break;
				if (dist[j] > dist[i] + adj[i][j])
				{
					negativeCycle = true;
				}
			}
		}

		if (negativeCycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}