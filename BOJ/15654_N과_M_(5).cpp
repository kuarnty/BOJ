/*
n���� ����(nums�� ��� ����) �� m ���� ���ϴ� ����(������������)
���� cnt�� 0���� �÷� ���鼭 m���� �� �� ���� ���ڸ� arr�� ä��
���ڰ� �ϳ� �� á���� �ش� ���� ���� visited�� true�� �ٲٰ� cnt�� �÷� dfs ����
(�̷��� �ϸ� ������ ä���� ����(�� ������ ä���� ����)�� visited �� true �̹Ƿ� �ߺ����� �߰����� ���� �� ����)
���� �߰��ϴ� ���ڴ� 0���� ������� ���Ͽ� �ڿ������� ������������ ������ ��
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 9;

int n, m;

int nums[MAX] = { 0 };

int arr[MAX] = { 0 };
bool visited[MAX] = { 0 };

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = nums[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums[i] = num;
	}
	sort(nums, nums + n);

	dfs(0);

	return 0;
}