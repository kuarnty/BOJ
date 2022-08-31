#include <iostream>
#include <string>

using namespace std;

int index[26];

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 26; i++)
		index[i] = -1;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		int cur = s[i] - 'a';
		if (index[cur] == -1)
			index[cur] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << index[i] << ' ';


	return 0;
}