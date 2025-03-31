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

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long n, m, k;
	cin >> n >> m >> k;
	++n;
	++m;

	long long lcm = (long long)n * (m / gcd(n, m));

	int notPainted = k / n;
	int notVarnished = k / m;
	int notBoth = k / lcm;
	cout << k - notPainted - notVarnished + notBoth << " "
		<< notBoth << " "
		<< notVarnished - notBoth << " "
		<< notPainted - notBoth;

	return 0;
}