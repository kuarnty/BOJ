#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

vector<int> pi;
vector<int> matchedPos;

void getPi(string p)
{
	int length = p.length();
	pi = vector<int>(length, 0);

	int matched = 0, sufHead = 1;

	while (matched + sufHead < length)
	{
		if (p[matched] == p[sufHead + matched])
		{
			matched++;
			pi[sufHead + matched - 1] = matched;
		}
		else
		{
			// non of just before matched
			if (matched == 0)
				sufHead++;

			// some of just before matched
			// => skip matched length,
				// but consider matched suffix, (some of suffix of what we want to skip may be same with some of prefix) 
				// so cancel(skipping) of the length pi[matched-1] (max matched length of the (*matched* length of pattern)
			else
			{
				sufHead += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

void kmp(string t, string p)
{
	int n = t.length();
	int m = p.length();

	int sufHead = 0, matched = 0;

	while (sufHead <= n - m)
	{
		if (matched < m && t[sufHead + matched] == p[matched])
		{
			matched++;
			if (matched == m)
				matchedPos.push_back(sufHead);
		}
		else
		{
			if (matched == 0)
				sufHead++;
			else
			{
				sufHead += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	getPi(P);
	kmp(T, P);

	cout << matchedPos.size() << endl;
	for (int i = 0; i < matchedPos.size(); i++)
		cout << matchedPos[i] + 1 << endl;

	return 0;
}