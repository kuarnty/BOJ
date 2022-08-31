#include <iostream>
#include <vector>
#include <algorithm>

#define endl			"\n"
#define INT_MAX			2147483647
#define LONG_LONG_MAX	9223372036854775807

#define ABS(A) (((A)>(0))?(A):(-A))

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int a = -1;
	int b = -1;
	int c = -1;
	long long result = LONG_LONG_MAX;

	for (int fix = 1; fix < n - 1; fix++)
	{
		int left = fix - 1;
		int right = fix + 1;
		long long neut = v[fix] + v[left] + v[right];

		while (left >= 0 && right <= n - 1)
		{
			neut = v[left] + v[fix] + v[right];
			if (neut == 0)
			{
				cout << v[left] << ' ' << v[fix] << ' ' << v[right];
				exit(0);
			}

			if (ABS(neut) < ABS(result))
			{
				a = left;
				b = fix;
				c = right;
				result = neut;
			}

			if (neut < 0)
			{
				if (right < n - 1)
					right++;
				else
					break;
			}
			else
			{
				if (left > 0)
					left--;
				else
					break;
			}
		}
	}

	cout << v[a] << ' ' << v[b] << ' ' << v[c];

	return 0;
}