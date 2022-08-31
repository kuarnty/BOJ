#include <iostream>
#include <vector>
#include <algorithm>

#define ABS(A) (((A)>(0))?(A):(-A))

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int left = 0;
	int right = n - 1;

	int neut = v[left] + v[right];

	int leftResult = left;
	int rightResult = right;
	int neutResult = neut;

	while (left < right)
	{
		neut = v[left] + v[right];
		if (ABS(neut) < ABS(neutResult))
		{
			leftResult = left;
			rightResult = right;
			neutResult = neut;
		}

		if (neut > 0)
		{
			right--;

		}
		else if (neut < 0)
		{
			left++;
		}
		else
		{
			break;
		}
	}

	cout << v[leftResult] << ' ' << v[rightResult];

	return 0;
}