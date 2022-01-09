//#include <iostream>
//#include <set>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		 set: 노드 기반 컨테이너. key 값이 중복 불가. 입력된 원소들은 자동으로 정렬됨(오름차순)
//		 multiset: key가 중복 가능한 set
//		multiset<int> ms;
//
//		int k;
//		cin >> k;
//
//		for (int i = 0; i < k; i++)
//		{
//			char oper;
//			cin >> oper;
//			if (oper == 'I')
//			{
//				int n;
//				cin >> n;
//				ms.insert(n);
//			}
//			else
//			{
//				int c;
//				cin >> c;
//
//				if (!ms.empty())
//				{
//					if (c == 1)
//					{
//						multiset<int>::iterator iter = ms.end();
//						iter--;
//						ms.erase(iter);
//					}
//					else
//					{
//						ms.erase(ms.begin());
//					}
//				}
//			}
//		}
//
//		if (ms.empty())
//		{
//			cout << "EMPTY" << endl;
//		}
//		else
//		{
//			multiset<int>::iterator iter = ms.end();
//			iter--;
//			cout << *iter << ' ' << *(ms.begin()) << endl;
//		}
//	}
//
//	return 0;
//}