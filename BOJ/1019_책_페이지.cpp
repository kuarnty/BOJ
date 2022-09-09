#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

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

#define ll long long

using namespace std;

vector<ll> result(10, 0);
vector<ll> preSum;

void calc(int x, int num)
{
	while(x > 0)
	{
		result[x % 10] += num;
		x /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	int num = 1;
	int s = 1;

	while (s <= n) 
	{
		while (n % 10 != 9 && s <= n)
		{
			calc(n, num);
			n--;
		}

		if (n < s)
			break;

		while (s % 10 != 0 && s <= n)
		{
			calc(s, num);
			s++;
		}

		s /= 10;
		n /= 10;
		
		for (int i = 0; i < 10; i++)
		{
			result[i] += (n - s + 1) * num;
		}
		
		num *= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}