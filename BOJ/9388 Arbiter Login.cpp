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

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string original, password;
		cin >> original >> password;

		string capsLockError;
		string numError;
		string capsLockNumError;

		for (int j = 0; j < original.size(); j++)
		{
			int upperLowerDiff = 'a' - 'A';
			if (original[j] >= 'A' && original[j] <= 'Z')
			{
				capsLockError += original[j] + upperLowerDiff;
				capsLockNumError += original[j] + upperLowerDiff;
			}
			else if (original[j] >= 'a' && original[j] <= 'z')
			{
				capsLockError += original[j] - upperLowerDiff;
				capsLockNumError += original[j] - upperLowerDiff;
			}
			else
			{
				capsLockError += original[j];
			}

			if (original[j] >= '0' && original[j] <= '9')
				continue;
			else
				numError += original[j];
		}

		if(password == original)
			cout << "Case " << i + 1 << ": Login successful." << endl;
		else if (password == capsLockError)
			cout << "Case " << i + 1 << ": Wrong password. Please, check your caps lock key." << endl;
		else if (password == numError)
			cout << "Case " << i + 1 << ": Wrong password. Please, check your num lock key." << endl;
		else if (password == capsLockNumError)
			cout << "Case " << i + 1 << ": Wrong password. Please, check your caps lock and num lock keys." << endl;
		else
			cout << "Case " << i + 1 << ": Wrong password." << endl;
	}

	return 0;
}