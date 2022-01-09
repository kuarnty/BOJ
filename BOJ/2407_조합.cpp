///*
//nCm의 값은 (5 <= n, m <= 100) 범위에서 long long int 로도 처리할 수 없는 큰 값을 가질 수 있다.
//따라서 이런 큰 값의 계산(여기서는 덧셈만 필요)을 위해 string을 활용한다.
//
//또한 Combination 계산은 nCm = n-1Cr = n-1Cr-1 임을 활용하여 재귀적으로 계산하고
//이때 중복 계산을 피하기 위해 cache를 만들어 특정 nCm의 결과를 저장하고 사용한다.
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
//	// num1, num2 중 하나라도 더할 값이 남아 있거나
//	// sum 값이 남아 있는 경우(올림 된 수)
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
//	// 1의자리를 먼저, 가장 큰 자릿수의 수를 가장 마지막에 더했으므로 뒤집어주기
//	// result 가 string& 이므로 여기에 값을 넣어 줘야 cache에 값이 업데이트 됨
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
//	// 이미 계산된 값인 경우
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