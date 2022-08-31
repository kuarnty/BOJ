#include <iostream>

#define endl			'\n'

using namespace std;

int cnt = 0;

int choice[100001];
bool visited[100001];
bool visiting[100001];

int dfs(int node)
{
	// 혼자 팀을 이루는 경우
	if (choice[node] == node)
	{
		visited[node] = true;
		return -1;
	}

	// 현재 스트릭의 학생들은 모두 팀을 이루게 됨
	if (visiting[node])
	{
		return node;
	}
	// 현재 스트릭의 학생들은 팀을 이루지 못함
	else if (visited[node])
	{
		return -1;
	}

	visited[node] = true;
	visiting[node] = true;
	int result = dfs(choice[node]);

	visiting[node] = false;

	// 스트릭 너머 어딘가에서 팀을 이루지 못한 경우
	if (result == -1)
	{
		cnt++;
		return -1;
	}
	else if (result != node)
	{
		return result;
	}
	else
	{
		return -1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> choice[i];
			visited[i] = visiting[i] = false;
		}
		cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}
		cout << cnt << endl;
	}

	return 0;
}