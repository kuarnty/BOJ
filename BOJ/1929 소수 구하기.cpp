#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define NUM_MAX		1000000

using namespace std;

bool isPrime[NUM_MAX + 1];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	fill(begin(isPrime), end(isPrime), true);
	isPrime[1] = false;

	long long m, n;
	cin >> m >> n;

	for (long long i = 2; i <= n; i++)
	{
		if (isPrime[i])
			for (long long j = 2; i * j <= n; j++)
				isPrime[i * j] = false;
	}

	for (int i = m; i <= n; i++)
		if (isPrime[i])
			cout << i << endl;

	return 0;
}