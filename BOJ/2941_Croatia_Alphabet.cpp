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
						count--; // 'd' ������ �� 'z='�� ī��Ʈ�ؾ� �ϹǷ� i++�� �������� ����
					// 'z='�� ���� ī��Ʈ�� ���̹Ƿ� 2�� �� ���� �ʰ� 1�� ����
				}
			}
		}
	}

	cout << count;

	return 0;
}
*/