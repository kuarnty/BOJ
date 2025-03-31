/*
n개의 숫자(nums에 들어 있음) 중 m 개를 택하는 문제(오름차순으로)
따라서 cnt를 0부터 늘려 가면서 m개가 될 때 까지 숫자를 arr에 채움
숫자가 하나 더 찼으니 해당 숫자 값의 visited를 true로 바꾸고 cnt를 늘려 dfs 시행
(이렇게 하면 직전에 채워진 숫자(및 이전에 채워진 숫자)는 visited 가 true 이므로 중복으로 추가하지 않을 수 있음)
또한 추가하는 숫자는 0부터 순서대로 취하여 자연스럽게 오름차순으로 나오게 함
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