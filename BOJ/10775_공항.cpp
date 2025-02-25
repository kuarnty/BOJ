// UNSOLVED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int G, P;
	cin >> G >> P;
	vector<int> g(P+1);
	for (int i = 1; i <= P; i++)
		cin >> g[i];

	int docked = 0;
	int last = 0;
	for (int i = 1; i <= P; i++)
	{
		if (last >= G || last >= g[i])
		{
			cout << docked;
			return 0;
		}

		last++;
		docked++;
	}

	cout << docked;

	return 0;
}