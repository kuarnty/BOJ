#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

unsigned long long int result[91] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	result[1] = 1;
	result[2] = 1;
	result[3] = 2;

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		result[i] = 2 * result[i - 2] + result[i - 3];
	}

	cout << result[n];

	return 0;
}