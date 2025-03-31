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

#define MAX_N	1000000

using namespace std;

typedef long long ll;
typedef long double ld;

struct Line
{
	ll a, b;	// ax + b
	ld crossX;	// x of intersection point
};

int n, a, b, c;
int X[MAX_N];
ll prefixSum[MAX_N];
ll dp[MAX_N];

int top = -1;
vector<Line> lines(MAX_N);

ld crossX(const Line& a, const Line& b)
{
	return (ld)(b.b - a.b) / (a.a - b.a);
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	cin >> a >> b >> c;
	cin >> X[0];
	prefixSum[0] = X[0];
	for (int i = 1; i < n; i++)
	{
		cin >> X[i];
		prefixSum[i] = X[i] + prefixSum[i - 1];
	}

	dp[0] = a * X[0] * X[0] + b * X[0] + c;
	int curLineIdx = 0;

	for (int i = 1; i < n; i++)
	{
		ll alpha = -2 * a * prefixSum[i - 1];
		ll beta = dp[i - 1] + a * prefixSum[i - 1] * prefixSum[i - 1] - b * prefixSum[i - 1];
		Line newLine = { alpha, beta, 0 };

		while (top >= 0)
		{
			Line l = lines[top];
			newLine.crossX = crossX(newLine, l);
			if (newLine.crossX < l.crossX)
				lines[top--] = newLine;
			else
				break;
		}
		lines[++top] = newLine;

		ll x = prefixSum[i];
		if (x >= lines[top].crossX)
			curLineIdx = top;
		else
		{
			int lo = curLineIdx;
			int hi = top;
			while (lo + 1 < hi)
			{
				int mid = (lo + hi) / 2;
				((x < lines[mid].crossX) ? hi : lo) = mid;
			}
			curLineIdx = lo;
		}
		
		// if left(nonzero) case is selected, it means that dividing is better
		// else(zero), not dividing (and making one team is better)
		// left(nonzero) case is calculated whlie omitting the constant term
		dp[i] = max(lines[curLineIdx].a * x + lines[curLineIdx].b, (ll)0) + a * x * x + b * x + c;
	}

	cout << dp[n - 1];

	return 0;
}