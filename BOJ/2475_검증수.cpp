#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	cout << (n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4 + n5 * n5) % 10;

	return 0;
}