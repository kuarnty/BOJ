#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int nums[8001];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	double sum = 0;

	int min = INT32_MAX;
	int max = INT32_MIN;
	int mostF = -1;

	vector<int> v(n);
	for (int i = 0; i < 8001; i++)
	{
		nums[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];

		if (v[i] > max)
			max = v[i];
		if (v[i] < min)
			min = v[i];
		nums[v[i] + 4000]++;
		if (nums[v[i] + 4000] > mostF)
			mostF = nums[v[i] + 4000];
	}

	vector<int> mf;
	for (int i = -4000; i <= 4000; i++)
	{
		if (nums[i + 4000] == mostF)
			mf.push_back(i);
	}

	sort(v.begin(), v.end());
	sort(mf.begin(), mf.end());

	cout << (int)round(sum / n) << endl;
	cout << v[n / 2] << endl;
	if (mf.size() == 1)
	{
		cout << mf[0] << endl;
	}
	else
	{
		cout << mf[1] << endl;
	}
	cout << max - min;


	return 0;
}