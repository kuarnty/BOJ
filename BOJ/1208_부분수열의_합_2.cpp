#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define endl			'\n'

using namespace std;

int seq[40];
map<long long, int>result;
long long cnt = 0;

int n;
int s;

void leftSum(int index, int sum)
{
	if (index == n / 2)
	{
		result[sum]++;
		return;
	}
	leftSum(index + 1, sum);
	leftSum(index + 1, sum + seq[index]);
}

void rightSum(int index, int sum)
{
	if (index == n)
	{
		cnt += result[s - sum];
		return;
	}
	rightSum(index + 1, sum);
	rightSum(index + 1, sum + seq[index]);
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	leftSum(0, 0);
	rightSum(n / 2, 0);

	if (s == 0)
		cnt--;

	cout << cnt;

	return 0;
}