#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string str;
	getline(cin, str);

	int cnt = 0;
	bool counting = false;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			if (counting)
				counting = false;
			else
				continue;
		}
		else
		{
			if (counting)
				continue;
			else
			{
				counting = true;
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}