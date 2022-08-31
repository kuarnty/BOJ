#include <iostream>
#include <vector>

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> val(n);
	vector<int> lis;

	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}

	lis.push_back(val[0]);

	for (int i = 1; i < n; i++)
	{
		if (lis[lis.size() - 1] < val[i])
			lis.push_back(val[i]);
		else
		{
			int s = 0;
			int e = lis.size() - 1;
			int m = (s + e) / 2;
			while (s < e)
			{
				if (lis[m] == val[i])
				{
					m = -1;
					break;
				}
				else if (lis[m] > val[i])
				{
					if ((m > 0) && (lis[m - 1] < val[i]))
						break;
					e = m - 1;
					m = (s + e) / 2;
				}
				else
				{
					s = m + 1;
					m = (s + e) / 2;
				}
			}
			if (m != -1)
			{
				lis[m] = val[i];
			}
		}
	}

	cout << lis.size();

	return 0;
}