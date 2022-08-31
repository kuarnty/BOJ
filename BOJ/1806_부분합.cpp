#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int a = 0, b = 0;
	int sum = v[0];
	int l = 100001;

	while (b < n)
	{
		if (sum >= s)
		{
			if (l > b - a + 1)
			{
				l = b - a + 1;
			}
			sum -= v[a++];
		}
		else
		{
			b++;
			if (b >= n)
				break;
			else
				sum += v[b];
		}
	}

	if (l == 100001)
		cout << 0;
	else
		cout << l;

	return 0;
}