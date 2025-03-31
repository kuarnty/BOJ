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

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	map<int, int, greater<int>> treesOfHeight;
	treesOfHeight[0] = 0; // let 0 trees of height 0
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;
		treesOfHeight[height]++;
	}

	long long heightSum = 0;
	long long upperHeightCount = 0;
	long long upperHeight, lowerHeight;
	auto height = treesOfHeight.begin();
	do
	{
		upperHeight = height->first;
		upperHeightCount += height->second;
		height++;
		lowerHeight = height->first;

		heightSum += (upperHeight - lowerHeight) * upperHeightCount;

		// searched all trees
		if (lowerHeight == 0)
			break;

	} while (heightSum < m);

	if (heightSum > m)
	{
		long long diff = heightSum - m;
		long long cutHeight = lowerHeight + (diff / upperHeightCount); // lowerHeight and upperHeightCount: last added height and the count
		cout << cutHeight;
	}
	else // heightSum == m
		cout << lowerHeight;

	return 0;
}