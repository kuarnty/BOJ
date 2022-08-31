#include <iostream>

#define INT_MAX			17000000
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

#define NAX_CITY_NUMBER	16
#define START_CITY		0

using namespace std;

int adj[16][16];
int dp[1 << NAX_CITY_NUMBER][NAX_CITY_NUMBER];

int TSP(int visited, int now, int n)
{
	visited |= (1 << now);

	// visited all cities
	if (visited == (1 << n) - 1)
	{
		// able to return to start city
		if (adj[now][START_CITY] > 0)
			return adj[now][START_CITY];
		else
			return INT_MAX;
	}

	int& ret = dp[visited][now];

	// if already calculated
	if (ret > 0)
		return ret;

	ret = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		// of the unvisited cities,
		// if able to go to city number i
		if ((i != now) && ((visited & (1 << i)) == 0) && (adj[now][i] > 0))
		{
			int temp = TSP(visited, i, n) + adj[now][i];
			if (ret > temp)
				ret = temp;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	int ret = TSP(0, START_CITY, n);
	// Since the input is always valid
	cout << ret;

	return 0;
}