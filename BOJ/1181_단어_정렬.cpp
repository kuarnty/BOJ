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
//		// 첫 단어는 그냥 추가
//		if (v.size() == 0)
//			v.push_back(s);
//		else
//		{
//			for (int j = 0; j < v.size(); j++)
//			{
//				// 해당 단어가 더 짧을 경우 (-> 길이 우선순위에서 앞서므로 바로 앞에 배치)
//				if (v[j].length() > s.length())
//				{
//					v.insert(v.begin() + j, s);
//					break;
//				}
//				// 해당 단어가 더 길 경우 -> 마지막인 경우 맨 뒤에 추가, 아니면 다음 단어로 넘어감
//				else if (v[j].length() < s.length())
//				{
//					if (j == v.size() - 1)
//						v.push_back(s);
//					else
//						continue;
//				}
//				// 해당 단어와 같은 길이의 단어와 마주칠 경우
//				else if (v[j].length() == s.length())
//				{
//					bool inserted = false;
//					for (int k = 0; k < s.length(); k++)
//					{
//						// s가 v보다 사전 순서로 앞설 경우 (-> 앞에 추가)
//						if (s[k] < v[j][k])
//						{
//							v.insert(v.begin() + j, s);
//							inserted = true;
//							break;
//						}
//						// s가 v보다 사전 순서로 늦을 경우 -> 마지막인 경우 맨 뒤에 추가, 아니면 다음 단어로 넘어감 
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
//						// 같은 문자라서 뒤를 더 봐야 하는 경우 -> 같은 단어이므로 생략 / 다음 문자로 넘어감
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