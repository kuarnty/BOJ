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

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> vertices(n);
		for (int i = 0; i < n; i++)
			cin >> vertices[i].first>>vertices[i].second;

		pair<int, int> v = { 0,0 };

		for (int i = 0; i < n / 2; i++)
		{
			v.first = v.first + vertices[i].first - vertices[i + i / 2].first;
			v.second = v.second + vertices[i].second - vertices[i + i / 2].second;
		}

		int min = v.first * v.first + v.second + v.second;


		
	}

	return 0;
}