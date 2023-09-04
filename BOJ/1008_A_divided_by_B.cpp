#include <iostream>

using namespace std;

int main()
{
	long double A, B;
	cin >> A >> B;

	// 출력 시 double 자료형은 기본 출력 형식이 소수점 아래 6자리까지로 되어 있다. 따라서 
	// scanf 사용 시 %[소수점 자리 수]f 나 %[소수점 자리 수]lf 를 사용해주어야 한다.
	// 
	// cout 사용 시 std::cout.precision(총 자리수) 로 자리수를 정해 줄 수 있다.
	// 여기서 만약 소수점 아래로 자리수를 정해주고 싶다면 std::cout << std::fixed;를 해 주거나 std::cout.setf(ios::fixed)를 해 준다.
	// 해제하고 싶다면 std::.cout.unsetf(ios::fixed)를 해 준다.

	cout << fixed;
	cout.precision(10);
	cout << A / B;

	return 0;
}