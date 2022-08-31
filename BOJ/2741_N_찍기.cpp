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
	for (int i = 0; i < n; i++)
		cout << i + 1 << endl;

	return 0;
}