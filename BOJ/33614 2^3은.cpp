#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl			'\n'

using namespace std;

int t, p, q, r;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> p >> q >> r;
		cout << p + min(q, r) - 1 << endl;
	}

	return 0;
}