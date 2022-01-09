///*
//nCm�� ���� (5 <= n, m <= 100) �������� long long int �ε� ó���� �� ���� ū ���� ���� �� �ִ�.
//���� �̷� ū ���� ���(���⼭�� ������ �ʿ�)�� ���� string�� Ȱ���Ѵ�.
//
//���� Combination ����� nCm = n-1Cr = n-1Cr-1 ���� Ȱ���Ͽ� ��������� ����ϰ�
//�̶� �ߺ� ����� ���ϱ� ���� cache�� ����� Ư�� nCm�� ����� �����ϰ� ����Ѵ�.
//*/
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//const int MAX = 101;
//
//string cache[MAX][MAX] = { "" };
//
//string BigNumAdd(string num1, string num2)
//{
//	long long sum = 0;
//	string result;
//
//	// num1, num2 �� �ϳ��� ���� ���� ���� �ְų�
//	// sum ���� ���� �ִ� ���(�ø� �� ��)
//	while (!num1.empty() || !num2.empty() || sum)
//	{
//		if (!num1.empty())
//		{
//			sum += num1.back() - '0';
//			num1.pop_back();
//		}
//
//		if (!num2.empty())
//		{
//			sum += num2.back() - '0';
//			num2.pop_back();
//		}
//
//		result.push_back((sum % 10) + '0');
//		sum /= 10;
//	}
//
//	// 1���ڸ��� ����, ���� ū �ڸ����� ���� ���� �������� �������Ƿ� �������ֱ�
//	// result �� string& �̹Ƿ� ���⿡ ���� �־� ��� cache�� ���� ������Ʈ ��
//	reverse(result.begin(), result.end());
//
//	return result;
//}
//
//// nCr = (n-1)C(r-1) + (n-1)Cr
//string Combination(int n, int r)
//{
//	if (n == r || r == 0)
//	{
//		return "1";
//	}
//
//	string& result = cache[n][r];
//	// �̹� ���� ���� ���
//	if (result != "")
//	{
//		return result;
//	}
//	else
//	{
//		result = BigNumAdd(Combination(n - 1, r - 1), Combination(n - 1, r));
//		return result;
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n, m;
//	cin >> n >> m;
//
//	cout << Combination(n, m);
//
//	return 0;
//}