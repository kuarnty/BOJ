#include <iostream>
#include <vector>
#include <algorithm>

#define endl			'\n'

using namespace std;

int arr[1000000];
int dp[1000000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> l;

	int maxLength = 0;
	int maxIndex = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		int cur = arr[i];

		if (l.size() == 0)
		{
			l.push_back(cur);
			dp[i] = 1;
		}
		else
		{
			// push back cur to l
			if (l[l.size() - 1] < cur)
			{
				l.push_back(cur);
				dp[i] = l.size();
			}
			// change lower bound
			else
			{
				vector<int>::iterator index = lower_bound(l.begin(), l.end(), arr[i]);
				*index = arr[i];
				dp[i] = index - l.begin() + 1;
			}
		}
		if (dp[i] > maxLength)
		{
			maxLength = dp[i];
			maxIndex = i;
		}
	}

	vector<int> s;
	s.push_back(arr[maxIndex]);
	for (int i = maxIndex - 1; i >= 0; i--)
	{
		if (arr[i] < arr[maxIndex] && dp[i] == dp[maxIndex] - 1)
		{
			maxIndex = i;
			s.push_back(arr[i]);
		}
	}
	cout << l.size() << endl;
	for (int i = s.size()-1; i >=0; i--)
	{
		cout << s[i] << ' ';
	}

	return 0;
}