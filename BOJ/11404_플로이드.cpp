#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

#define MAX 1000000000
#define MIN(A,B) (A) < (B) ? (A) : (B)

using namespace std;

int adj[100][100];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			adj[i][j] = i == j ? 0 : MAX;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a][b] = MIN(adj[a][b], c);
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adj[i][j] == MAX)
				cout << 0;
			else
				cout << adj[i][j];

			if (j != n - 1)
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}