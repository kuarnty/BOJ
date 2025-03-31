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

#define MAX_NUM		4000

using namespace std;

int n;
int a[MAX_NUM], b[MAX_NUM], c[MAX_NUM], d[MAX_NUM];
vector<int> ab, cd;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	ab.reserve(n * n * sizeof(int));
	cd.reserve(n * n * sizeof(int));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long long zeroCnt = 0;
	int abIdx = 0;
	int cdIdx = cd.size() - 1;
	while (abIdx < ab.size() && cdIdx >= 0)
	{
		if (ab[abIdx] + cd[cdIdx] == 0)
		{
			long long abCnt = 1, cdCnt = 1;
			while (++abIdx < ab.size() && ab[abIdx - 1] == ab[abIdx])
				abCnt++;
			while (--cdIdx >= 0 && cd[cdIdx + 1] == cd[cdIdx])
				cdCnt++;
			zeroCnt += abCnt * cdCnt;
		}
		else if (ab[abIdx] + cd[cdIdx] > 0)
			cdIdx--;
		else //(ab[abIdx] + cd[cdIdx] < 0)
			abIdx++;
	}

	cout << zeroCnt << endl;

	return 0;
}