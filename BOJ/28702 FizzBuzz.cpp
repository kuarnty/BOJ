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

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	const string fizz = "Fizz";
	const string buzz = "Buzz";
	const string fizzBuzz = "FizzBuzz";

	int fourth = 0;

    if (s1 != fizz && s1 != buzz && s1 != fizzBuzz)
    fourth = stoi(s1) + 3;
    else if (s2 != fizz && s2 != buzz && s2 != fizzBuzz)
    fourth = stoi(s2) + 2;
    else if (s3 != fizz && s3 != buzz && s3 != fizzBuzz)
    fourth = stoi(s3) + 1;
	
	if (fourth % 15 == 0)
		cout << fizzBuzz;
	else if (fourth % 5 == 0)
		cout << buzz;
	else if (fourth % 3 == 0)
		cout << fizz;
	else
		cout << fourth;

	return 0;
}