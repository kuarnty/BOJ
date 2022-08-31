#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

int sequence[100000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	int max = sequence[0];
	for (int i = 1; i < n; i++)
	{
		if (sequence[i - 1] >= 0 && sequence[i - 1] + sequence[i] > 0)
			sequence[i] += sequence[i - 1];

		if (sequence[i] > max)
			max = sequence[i];
	}

	cout << max;

	return 0;
}