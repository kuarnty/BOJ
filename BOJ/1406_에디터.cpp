//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	list<char> l;
//	bool atFirst = false;
//
//	 �ʱ� �Է�
//
//	string s;
//	cin >> s;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		l.push_back(s[i]);
//	}
//
//	int n;
//	cin >> n;
//
//	 iter�� ����Ű�� ������ �����ʿ� Ŀ���� �ִٰ� ����
//	list<char>::iterator iter = l.end();
//
//	 ��ɾ� ó��
//	for (int i = 0; i < n; i++)
//	{
//		char command;
//		cin >> command;
//
//		switch (command)
//		{
//		case 'L':
//			if (!atFirst)
//			{
//				if (iter == l.begin())
//					atFirst = true;
//				else
//					iter--;
//			}
//			break;
//
//		case 'D':
//			if (atFirst)
//			{
//				atFirst = false;
//			}
//			else
//			{
//				if (iter != l.end())
//					iter++;
//			}
//			break;
//
//		case 'B':
//			if (!atFirst)
//			{
//				if (iter == l.begin())
//					atFirst = true;
//				l.erase(iter);
//			}
//			break;
//
//		case 'P':
//			char c;
//			cin >> c;
//
//			if (atFirst)
//			{
//				l.push_front(c);
//				atFirst = false;
//			}
//			else
//				l.insert(iter, c);
//
//			break;
//
//		default:
//			break;
//		}
//	}
//
//	int listSize = l.size();
//	for (int i = 0; i < listSize; i++)
//	{
//		cout << l.front();
//		l.pop_front();
//	}
//
//	return 0;
//}