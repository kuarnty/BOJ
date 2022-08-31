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
	for (int i = n; i >= 1; i--)
		cout << i << endl;
	return 0;
}