#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

long long arr[100001];

int BinarySearch(int endIndex, long long value)
{
	int startIndex = 0;
	int mid;

	while (endIndex >= startIndex)
	{
		mid = (startIndex + endIndex) / 2;

		if (arr[mid] == value)
		{
			return 1;
		}
		else if (value < arr[mid])
		{
			endIndex = mid - 1;
		}
		else
		{
			startIndex = mid + 1;
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int M = 0;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		long long value = 0;
		cin >> value;
		cout << BinarySearch(N - 1, value) << endl;
	}

	return 0;
}