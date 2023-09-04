#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, x;
	cin >> n >> x;

	vector<int> seq(n);
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	for (int i = 0; i < n; i++)
	{
		if (seq[i] < x)
		{
			cout << seq[i] << ' ';
		}
	}

	return 0;
}