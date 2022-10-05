#include <iostream>
#include <vector>

using namespace std;

int a[5000];
bool weight[800000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] > w)
				continue;

			if (weight[w - (a[i] + a[j])])
			{
				cout << "YES";
				return 0;
			}
		}

		for (int j = 0; j < i; j++)
			if (a[i] + a[j] < w)
				weight[a[i] + a[j]] = true;
	}

	cout << "NO";

	return 0;
}