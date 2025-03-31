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

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string operations;
		int n;
		string s;
		cin >> operations >> n >> s;

		vector<int> arr;

		if (s.length() <= 2)
		{
			if (operations.find('D') != string::npos)
				cout << "error" << endl;
			else
				cout << "[]" << endl;
		}
		else
		{
			s = s.substr(1, s.length() - 2);
			s.push_back(',');

			string separator = ",";
			int curPos = 0;
			int separatorPos = 0;
			while ((separatorPos = s.find(separator, curPos)) != string::npos)
			{
				arr.push_back(stoi(s.substr(curPos, separatorPos - curPos)));
				curPos = separatorPos + 1;
			}

			bool failed = false;
			bool reversed = false;
			int head = 0, tail = arr.size() - 1;
			for (int i = 0; i < operations.size(); i++)
			{
				if (operations[i] == 'R')
					reversed = !reversed;
				else // (operations[i] == 'D')
				{
					if (head > tail)
					{
						failed = true;
						break;
					}
					else
						!reversed ? ++head : --tail;
				}
			}

			if (failed)
				cout << "error" << endl;
			else
			{
				cout << '[';
				if (!reversed)
					for (int i = head; i <= tail; i++)
						cout << arr[i] << (i < tail ? "," : "");
				else
					for (int i = tail; i >= head; i--)
						cout << arr[i] << (i > head ? "," : "");
				cout << ']' << endl;
			}
		}
	}

	return 0;
}