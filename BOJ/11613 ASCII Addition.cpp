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


//		xxxxx  ....x  xxxxx  xxxxx  x...x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  .....
//		x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..
//		x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..
//		x...x  ....x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  ....x  xxxxx  xxxxx  xxxxx
//		x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..
//		x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..
//		xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  .....

string asciiNum[10][7] = {
	{
		"xxxxx",
		"x...x",
		"x...x",
		"x...x",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"xxxxx",
		"x....",
		"x....",
		"xxxxx"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	},
	{
		"x...x",
		"x...x",
		"x...x",
		"xxxxx",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"x....",
		"x....",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	},
	{
		"xxxxx",
		"x....",
		"x....",
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	}
};

int asciiToExpressionAndCalcuate(string(&ascii)[7])
{
	int nums[2] = { 0, 0 };
	int numIndex = 0;
	for (int j = 0; j < ascii[0].length(); j += 6)
	{
		// 1 or +
		if (ascii[0][j] == '.')
		{
			// 1
			if (ascii[0][j + 4] == 'x')
				nums[numIndex] = nums[numIndex] * 10 + 1;
			// +
			else
				++numIndex;
		}
		// 4
		else if (ascii[0][j + 1] == '.')
			nums[numIndex] = nums[numIndex] * 10 + 4;
		// 2, 3 or 7
		else if (ascii[1][j] == '.')
		{
			if (ascii[3][j] == '.')
				nums[numIndex] = nums[numIndex] * 10 + 7;
			else if (ascii[4][j] == 'x')
				nums[numIndex] = nums[numIndex] * 10 + 2;
			else
				nums[numIndex] = nums[numIndex] * 10 + 3;
		}

		// 0, 5, 6, 8 or 9
		else
		{
			if (ascii[3][j + 1] == '.')
				nums[numIndex] = nums[numIndex] * 10 + 0;
			// 5 or 6
			else if (ascii[1][j + 4] == '.')
			{
				if (ascii[4][j] == '.')
					nums[numIndex] = nums[numIndex] * 10 + 5;
				else
					nums[numIndex] = nums[numIndex] * 10 + 6;
			}
			// 8 or 9
			else
			{
				if (ascii[4][j] == 'x')
					nums[numIndex] = nums[numIndex] * 10 + 8;
				else
					nums[numIndex] = nums[numIndex] * 10 + 9;

			}

		}
	}

	return nums[0] + nums[1];
}

string* numToAscii(int num)
{
	vector<int> digits;
	while (num > 0)
	{
		int t = num % 10;
		digits.push_back(t);
		num /= 10;
	}

	string* ascii = new string[7];
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		int digit = digits[i];
		for (int i = 0; i < 7; i++)
			ascii[i].append(asciiNum[digit][i]);
		if (i > 0)
			for (int i = 0; i < 7; i++)
				ascii[i].append(".");
	}
	return ascii;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string ascii[7];
	for (int i = 0; i < 7; i++)
		cin >> ascii[i];
	int num = asciiToExpressionAndCalcuate(ascii);
	string* result = numToAscii(num);
	for (int i = 0; i < 7; i++)
		cout << result[i] << endl;
	delete[] result;

	return 0;
}

//		xxxxx  ....x  xxxxx  xxxxx  x...x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  .....
//		x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..
//		x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..
//		x...x  ....x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  ....x  xxxxx  xxxxx  xxxxx
//		x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..
//		x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..
//		xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  .....
// 
// 
//		....x  .....
//		....x  ..x..
//		....x  ..x..
//		....x  xxxxx
//		....x  ..x..
//		....x  ..x..
//		....x  .....
// 
//		x...x
// 		x...x
// 		x...x
// 		xxxxx
// 		....x
// 		....x
// 		....x
// 
//		xxxxx  xxxxx  xxxxx  
// 		....x  ....x  ....x  
// 		....x  ....x  ....x  
// 		....x  xxxxx  xxxxx  
// 		....x  x....  ....x  
// 		....x  x....  ....x  
// 		....x  xxxxx  xxxxx  
// 
//		xxxxx		xxxxx  xxxxx		xxxxx  xxxxx  
//		x...x		x....  x....		x...x  x...x  
//		x...x		x....  x....		x...x  x...x  
//		x...x		xxxxx  xxxxx		xxxxx  xxxxx  
//		x...x		....x  x...x		x...x  ....x  
//		x...x		....x  x...x		x...x  ....x  
//		xxxxx		xxxxx  xxxxx		xxxxx  xxxxx  
