//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		// ù �ܾ�� �׳� �߰�
//		if (v.size() == 0)
//			v.push_back(s);
//		else
//		{
//			for (int j = 0; j < v.size(); j++)
//			{
//				// �ش� �ܾ �� ª�� ��� (-> ���� �켱�������� �ռ��Ƿ� �ٷ� �տ� ��ġ)
//				if (v[j].length() > s.length())
//				{
//					v.insert(v.begin() + j, s);
//					break;
//				}
//				// �ش� �ܾ �� �� ��� -> �������� ��� �� �ڿ� �߰�, �ƴϸ� ���� �ܾ�� �Ѿ
//				else if (v[j].length() < s.length())
//				{
//					if (j == v.size() - 1)
//						v.push_back(s);
//					else
//						continue;
//				}
//				// �ش� �ܾ�� ���� ������ �ܾ�� ����ĥ ���
//				else if (v[j].length() == s.length())
//				{
//					bool inserted = false;
//					for (int k = 0; k < s.length(); k++)
//					{
//						// s�� v���� ���� ������ �ռ� ��� (-> �տ� �߰�)
//						if (s[k] < v[j][k])
//						{
//							v.insert(v.begin() + j, s);
//							inserted = true;
//							break;
//						}
//						// s�� v���� ���� ������ ���� ��� -> �������� ��� �� �ڿ� �߰�, �ƴϸ� ���� �ܾ�� �Ѿ 
//						else if (s[k] > v[j][k])
//						{
//							if (j == v.size() - 1)
//							{
//								v.push_back(s);
//								inserted = true;
//								break;
//							}
//							else
//								break;
//						}
//						// ���� ���ڶ� �ڸ� �� ���� �ϴ� ��� -> ���� �ܾ��̹Ƿ� ���� / ���� ���ڷ� �Ѿ
//						else if (s[k] == v[j][k])
//						{
//							if (k == s.length() - 1)
//							{
//								inserted = true;
//								break;
//							}
//							else
//								continue;
//						}
//					}
//					if (inserted)
//						break;
//					else
//						continue;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << endl;
//	}
//
//	return 0;
//}