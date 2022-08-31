#include <iostream>

#define endl			'\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n - i)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}