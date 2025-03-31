/*
			f(0)	= 0
			f(1)	= 1
			f(2)	= f(0) + f(1) = 0 + 1 = 1
			f(3)	= f(2) + f(1) = 1 + 1 = 2
			f(4)	= f(3) + f(2) = 2 + 1 = 3
			f(5)	= f(4) + f(3) = 3 + 2 = 5
			...
			f(n)	= f(n-1) + f(n-2)					f(2) * f(n-1) + f(1) * f(n-2)
						= {f(n-2) + f(n-3)} + f(n-2)
					= 2f(n-2) + f(n-3)					f(3) * f(n-2) + f(2) * f(n-3)
						= 2{f(n-3) + f(n-4)} + f(n-3)
					= 3f(n-3) + 2f(n-4)					f(4) * f(n-3) + f(3) * f(n-4)
						= 3{f(n-4) + f(n-5)} + 2f(n-4)
					= 5f(n-4) + 3f(n-5)					f(5) * f(n-4) + f(4) * f(n-5)
					= 8f(n-5) + 5f(n-6)					f(6) * f(n-5) + f(5) * f(n-6)
					= 13f(n-6) + 8f(n-7)				f(7) * f(n-6) + f(6) * f(n-7)
					...
	=> for some 1 <= k <= n,
	f(n)			= f(k+1) * f(n-k) + f(k) * f(n-(k+1))

	Then,
	1) for 2n,
		f(2n)		= f(k+1) * f(2n-k) + f(k) * f(2n-(k+1))
		Take k = n, then
			f(2n)	= f(n+1) * f(n) + f(n) * f(n-1)
					= f(n) * {f(n+1) + f(n-1)}						... (i)
					= f(n) * [{f(n) + f(n-1)} + f(n-1)]
					= f(n) * {f(n) + 2f(n-1)}						... (ii)
	# (ii) uses only 2 variables (f(n) and f(n-1))
	2) for 2n+1,
		f(2n+1)		= f(k+1) * f(2n+1-k) + f(k) * f(2n+1-(k+1))
		Take k = n, then
			f(2n+1)	= f(n+1) * f(n+1) + f(n) * f(n)
					= f(n+1)^2 + f(n)^2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <map>

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

#define ll		long long
#define DIV		1000000007LL

using namespace std;

map<ll, ll> mem;

ll fibonachi(ll n)
{
	if (n == 0) return 0;
	else if (n == 1 || n == 2) return 1;
	else if (mem.count(n) > 0) return mem[n];

	if (n % 2 == 0)
	{
		ll m = n / 2;
		ll t1 = fibonachi(m + 1);
		ll t2 = fibonachi(m);
		ll t3 = fibonachi(m - 1);
		mem[n] = (t2 * (t1 + t3)) % DIV;
		return mem[n];
	}
	else
	{
		ll m = (n - 1) / 2;
		ll t1 = fibonachi(m + 1);
		ll t2 = fibonachi(m);
		mem[n] = (t1 * t1 + t2 * t2) % DIV;
		return mem[n];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	ll n;
	cin >> n;
	cout << fibonachi(n);

	return 0;
}