#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cmath>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

using namespace std;

const long long r = 31;
const long long M = 1234567891;
long long powR[51];

void calcPowR()
{
	powR[0] = 1;
	for (int i = 1; i <= 50; i++)
		powR[i] = (powR[i - 1] * r) % M;
	return;
}

int hashFunc(string s)
{
	long long ret = 0;
	for (int i = 0; i < s.size(); i++)
		ret += ((s[i] - 'a' + 1) * powR[i]) % M;
	return ret % M;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int l;
	cin >> l;
	string s;
	cin >> s;

	calcPowR();

	cout << hashFunc(s);

	return 0;
}