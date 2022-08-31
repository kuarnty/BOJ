#include <iostream>

#define endl			'\n'

using namespace std;

int cnt = 0;

int choice[100001];
bool visited[100001];
bool visiting[100001];

int dfs(int node)
{
	// ȥ�� ���� �̷�� ���
	if (choice[node] == node)
	{
		visited[node] = true;
		return -1;
	}

	// ���� ��Ʈ���� �л����� ��� ���� �̷�� ��
	if (visiting[node])
	{
		return node;
	}
	// ���� ��Ʈ���� �л����� ���� �̷��� ����
	else if (visited[node])
	{
		return -1;
	}

	visited[node] = true;
	visiting[node] = true;
	int result = dfs(choice[node]);

	visiting[node] = false;

	// ��Ʈ�� �ʸ� ��򰡿��� ���� �̷��� ���� ���
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