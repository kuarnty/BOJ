#include <iostream>
//strlen은 cstring에 있다 쓰레기같은거

#define MAXVALUE(A, B) (((A) > (B)) ? (A) : (B))

using namespace std;

int score[301] = { 0, };
unsigned long long maxScore[301] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}

	maxScore[1] = score[1];
	maxScore[2] = score[1] + score[2];
	maxScore[3] = MAXVALUE(maxScore[1], score[2]) + score[3];

	for (int i = 4; i <= n; i++)
	{
		maxScore[i] = (MAXVALUE((maxScore[i - 2]), (maxScore[i - 3] + score[i - 1]))) + score[i];
	}

	cout << maxScore[n];

	return 0;
}