#include <iostream>
#include <string>

using namespace std;

string result(int r, string s)
{
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < r; j++)
		{
			result.push_back(s[i]);
		}
	}
	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int R;
		string S;
		cin >> R >> S;
		cout << result(R, S) << endl;
	}

	return 0;
}