#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <stack>

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
	stack<int> s;
	vector<int> output(n);
	vector<char> operators;
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> output[i];
		s.push(i + 1);
		operators.push_back('+');

		while (!s.empty() && s.top() == output[idx])
		{
			s.pop();
			operators.push_back('-');
			++idx;
		}

		if (!s.empty() && output[idx] < s.top())
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i = 0; i < operators.size(); i++)
		cout << operators[i] << endl;

	return 0;
}