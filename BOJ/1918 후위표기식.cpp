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

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string infix;
	cin >> infix;

	stack<char> s;

	for (int i = 0; i < infix.length(); i++)
	{
		switch (infix[i])
		{
		case '(':
			s.push(infix[i]);
			break;
		case '*':
		case '/':
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				cout << s.top();
				s.pop();
			}
			s.push(infix[i]);
			break;
		case '+':
		case '-':
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(infix[i]);
			break;
		case ')':
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			cout << infix[i];
			break;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}