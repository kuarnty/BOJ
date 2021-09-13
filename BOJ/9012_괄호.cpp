//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//		int count = 0;
//		bool VPS = false;
//		for (int j = 0; j < s.length(); j++)
//		{
//			if (count < 0)
//			{
//				VPS = false;
//				break;
//			}
//			else
//			{
//				if (s[j] == '(')
//					count++;
//				else
//					count--;
//			}
//		}
//
//		if (count == 0)
//		{
//			VPS = true;
//		}
//
//		if (VPS)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//	}
//
//	return 0;
//}