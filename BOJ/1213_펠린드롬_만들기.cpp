//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#include <cstring> // 추가 안하면 백준에서 오류남. strlen 때문인듯
//
//using namespace std;
//
//int main()
//{
//	char name[51];
//	char a = '0';
//
//	vector<char> answer;
//
//	cin >> name;
//
//	sort(name, name + strlen(name));
//
//	int j = 0;
//	for (int i = 0; i < strlen(name); i++)
//	{
//		if (name[i] == name[i + 1])
//		{
//			answer.insert(answer.begin() + j++, name[i]);
//			answer.insert(answer.begin() + j, name[i]);
//			i++;
//		}
//		else
//		{
//			if (a != '0')
//			{
//				cout << "I'm Sorry Hansoo";
//				return 0;
//			}
//			else
//			{
//				a = name[i];
//			}
//		}
//	}
//
//	if (a != '0')
//	{
//		answer.insert(answer.begin() + j, a);
//	}
//
//	for (int i = 0; i < answer.size(); i++)
//	{
//		cout << answer[i];
//	}
//
//	return 0;
//}