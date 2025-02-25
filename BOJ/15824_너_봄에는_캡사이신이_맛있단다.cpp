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

#define MENU_NUMBER		300000
#define MOD				1000000007

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

vector<long long> scoville;
long long expOf2[MENU_NUMBER];

void calcExp()
{
	long long e = 1;
	expOf2[0] = e;
	for (int i = 1; i < MENU_NUMBER; i++)
	{
		e <<= 1;
		if (e >= MOD)
			e -= MOD;
		expOf2[i] = e;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	calcExp();

	int n;
	cin >> n;
	scoville = vector<long long>(n);
	for (int i = 0; i < n; i++)
		cin >> scoville[i];

	sort(scoville.begin(), scoville.end());

	long long sum = 0;

	// Calculate maximum pain
	for (int i = 1; i < scoville.size(); i++)
	{		
		sum += (expOf2[i] - 1) * scoville[i];
		sum %= MOD;
	}

	// Calculate minimum pain
	for (int i = 0; i < scoville.size() - 1; i++)
	{
		sum -= (expOf2[n - i - 1] - 1) * scoville[i];
		sum %= MOD;
	}

	if (sum < 0)
		sum += MOD;

	cout << sum;

	return 0;
}