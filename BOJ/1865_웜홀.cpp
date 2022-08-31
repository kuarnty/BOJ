#include <iostream>
#include <vector>
#include <algorithm>
//strlen�� cstring�� �ִ� �����ⰰ����

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

			// ���� �߰�
			// ���ΰ� �������� �� ����. �ּڰ��� �߰�����! ��? -> ���� ����Ŭ�� �����ϸ� �Ǵϱ�!
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
			// ��Ȧ �߰�
			// ��Ȧ�� ���κ��� ���� ���� �� �ۿ� �����Ƿ� �׳� �߰��ص� ��
			adj[S][E] = -T;
		}

		for (int i = 1; i <= N; i++)
		{
			dist[i] = MAXVALUE;
		}
		// ������ sourceId 1
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