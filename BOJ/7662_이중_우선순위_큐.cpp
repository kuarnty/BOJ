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
//		 set: ��� ��� �����̳�. key ���� �ߺ� �Ұ�. �Էµ� ���ҵ��� �ڵ����� ���ĵ�(��������)
//		 multiset: key�� �ߺ� ������ set
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