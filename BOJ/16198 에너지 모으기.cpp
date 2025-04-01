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

using namespace std;

int maxEnergy = 0;

void getEnergy(vector<int> w, int energy)
{
	if (w.size() == 2)
	{
		maxEnergy = max(maxEnergy, energy);
		return;
	}

	for (int i = 1; i < w.size() - 1; i++)
	{
		vector<int> x = w;
		int newEnergy = x[i - 1] * x[i + 1];
		x.erase(x.begin() + i);
		getEnergy(x, energy + newEnergy);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];

	getEnergy(w, 0);

	cout << maxEnergy;

	return 0;
}