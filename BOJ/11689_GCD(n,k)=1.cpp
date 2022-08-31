#include <iostream>

#define endl "\n"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned long long n;
	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	unsigned long long phi = n;
	for (unsigned long long p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			phi -= phi / p;
			while (n % p == 0)
				n /= p;
		}
	}
	// n is product of every square-free prime factors
	if (n != 1)
	{
		phi -= phi / n;
	}

	cout << phi;

	return 0;
}