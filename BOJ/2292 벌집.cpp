/*
	Let
							start point							distance
		Lv.1: 1				1									1
		Lv.2: 2, ..., 7		2	= 1 + 1							2
		Lv.3: 8, ..., 19	8	= 2 + 6*1						3
		Lv.4: 20, ..., 37	20	= 2 + 6*(1+2)					4
		Lv.5: 38, ..., 61	38	= 2 + 6*(1+2+3)					5
		...
		Lv.n:					= 2 + 6*(1+2+...+(n-2))			n
								= 2 + 6*[{(n-1)*(n-2)} / 2]
								= 2 + 3*(n-1)*(n-2)
		but, also				= [Lv.n-1] + 6*(n-2)
	Thus, for some k,
		if (start point of Lv.n) <= k <= (start point of Lv.(n+1)),
		k is in Lv.n => distance is n
*/

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

	int n;
	cin >> n;
	int lv = 1;
	int start = 1;

	if (n == 1)
		cout << 1 << endl;
	else
	{
		lv = 2;
		start = 2;
		while (n >= start)
			start += 6 * (++lv - 2);
		// now lv is the just outer ring of the ring containing n
		cout << lv - 1 << endl;
	}

	return 0;
}