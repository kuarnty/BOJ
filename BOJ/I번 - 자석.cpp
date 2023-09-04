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

	int n, K;
	cin >> n >> K;
	vector<int> a(n);
	vector<int> d(n);
	vector<int> D(n);
	vector<int> mD(n, 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n == 2)
	{
		int r = a[0] - a[1] - K;
		r = MAX(r, a[1] - a[0] - K);
		cout << r;
		return 0;
	}

	// N-S

	int N = 0;
	int S = 1;
	d[S] = a[N] - a[S] - K * (S - N);
	D[S] = a[S] - a[N] + K;
	S++;

	for (; S < n; S++)
	{
		d[S] = d[S - 1] + a[S - 1] - a[S] - K;

		D[S] = a[S] - a[N] + K * (S - N);
		mD[S] = D[S] > D[mD[S - 1]] ? S : mD[S - 1];
	}

	int res = d[1];
	for (int i = 2; i < n; i++)
	{
		res = MAX(res, d[i]);
		if (D[mD[i - 1]] > 0)
		{
			res = MAX(res, d[i] + D[mD[i - 1]]);
		}
	}

	// S-N

	N = 1;
	S = 0;
	d[N] = a[N] - a[S] - K * (N - S);
	D[N] = a[S] - a[N] + K;
	N++;

	for (; N < n; N++)
	{
		d[N] = d[N-1] + a[N] - a[N-1] - K;

		D[N] = a[S] - a[N] + K * (N - S);
		mD[N] = D[N] > D[mD[N - 1]] ? N : mD[N-1];
	}

	res = MAX(res, d[1]);
	for (int i = 2; i < n; i++)
	{
		res = MAX(res, d[i]);
		if (D[mD[i - 1]] > 0)
		{
			res = MAX(res, d[i] + D[mD[i - 1]]);
		}
	}

	cout << res;

	return 0;
}