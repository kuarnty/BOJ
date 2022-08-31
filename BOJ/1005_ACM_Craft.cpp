#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"
#define MAX(A,B) ((A)>(B)?(A):(B))

using namespace std;

int building[1001];
int buildTime[1001];

vector<int> order[1001];
int indegree[1001];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> building[i];
			buildTime[i] = building[i];
		}
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			order[x].push_back(y);
			indegree[y]++;
		}

		int w;
		cin >> w;

		queue<int> q;

		for (int i = 1; i <= n; i++)
		{
			if (i == w)
				continue;
			if (indegree[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int i = 0; i < order[cur].size(); i++)
			{
				int next = order[cur][i];
				buildTime[next] = MAX(buildTime[next], buildTime[cur] + building[next]);

				if (--indegree[next] == 0)
					q.push(next);
			}
		}

		cout << buildTime[w] << endl;
		for (int i = 1; i <= n; i++)
		{
			order[i].clear();
			indegree[i] = 0;
		}
	}

	return 0;
}