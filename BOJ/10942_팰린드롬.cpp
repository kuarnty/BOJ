#include <iostream>

#define endl "\n"

using namespace std;

int seq[2000];
int p[2001][2001];

bool isPalindrome(int s, int e)
{
	if (s >= e)
		return true;

	if (p[s][e] == 0)
		p[s][e] = (isPalindrome(s + 1, e - 1) && (seq[s] == seq[e])) ? 1 : -1;

	return p[s][e] == 1;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int m;
	cin >> m;
	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		if (isPalindrome(s - 1, e - 1))
			cout << 1;
		else
			cout << 0;
		cout << endl;
	}

	return 0;
}