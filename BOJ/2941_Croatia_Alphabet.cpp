/*
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char word[101];
	cin >> word;
	int length = 0;
	length = strlen(word);
	int count = length;

	for (int i = 0; i < length; i++)
	{
		if (i == length - 1)
			continue;
		else
		{
			if (word[i] == 'c')
			{
				if (word[i + 1] == '=' || word[i + 1] == '-')
					count--; i++;
			}
			else if (word[i] == 'l' || word[i] == 'n')
			{
				if (word[i + 1] == 'j')
					count--; i++;
			}
			else if (word[i] == 's' || word[i] == 'z')
			{
				if (word[i + 1] == '=')
					count--; i++;
			}
			else if (word[i] == 'd')
			{
				if (word[i + 1] == '-')
				{
					count--; i++;
				}
				else if (word[i + 1] == 'z')
				{
					if (i + 1 == length - 1)
						continue;
					else if (word[i + 2] == '=')
						count--; // 'd' 다음에 올 'z='을 카운트해야 하므로 i++을 수행하지 않음
					// 'z='을 따로 카운트할 것이므로 2를 빼 주지 않고 1만 빼줌
				}
			}
		}
	}

	cout << count;

	return 0;
}
*/