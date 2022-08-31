#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

#define MAXVALUE(A, B) (((A) > (B)) ? (A) : (B))

using namespace std;

int glasses[10000];
int maxAlcohol[10000];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> glasses[i];

	maxAlcohol[0] = glasses[0];
	maxAlcohol[1] = glasses[0] + glasses[1];

	for (int i = 2; i < n; i++)
	{
		maxAlcohol[i] = MAXVALUE(MAXVALUE((maxAlcohol[i - 2]) + glasses[i], (maxAlcohol[i - 3] + glasses[i - 1] + glasses[i])), maxAlcohol[i - 1]);
	}

	cout << maxAlcohol[n - 1];

	return 0;
}