#include <iostream>

using namespace std;

int main()
{
	long double A, B;
	cin >> A >> B;

	// ��� �� double �ڷ����� �⺻ ��� ������ �Ҽ��� �Ʒ� 6�ڸ������� �Ǿ� �ִ�. ���� 
	// scanf ��� �� %[�Ҽ��� �ڸ� ��]f �� %[�Ҽ��� �ڸ� ��]lf �� ������־�� �Ѵ�.
	// 
	// cout ��� �� std::cout.precision(�� �ڸ���) �� �ڸ����� ���� �� �� �ִ�.
	// ���⼭ ���� �Ҽ��� �Ʒ��� �ڸ����� �����ְ� �ʹٸ� std::cout << std::fixed;�� �� �ְų� std::cout.setf(ios::fixed)�� �� �ش�.
	// �����ϰ� �ʹٸ� std::.cout.unsetf(ios::fixed)�� �� �ش�.

	cout << fixed;
	cout.precision(10);
	cout << A / B;

	return 0;
}