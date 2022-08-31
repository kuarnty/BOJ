#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	cout << a + b;

	return 0;
}