#include <iostream>

#define endl			'\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int h, m;
	cin >> h >> m;
	
	h = ((((h + 24) * 60 + m) - 45) % (24 * 60)) / 60;
	m = (m + 15) % 60;
	cout << h << ' ' << m;

	return 0;
}