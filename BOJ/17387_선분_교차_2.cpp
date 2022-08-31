#include <iostream>

#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

typedef long long ll;

using namespace std;

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	ll ccw123 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	ll ccw124 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);
	ll ccw134 = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
	ll ccw234 = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

	//		-		0		+
	// 
	//	-	����		��?		X
	// 
	//	0	��?		?		X
	// 
	//	+	X		X		X
	//
	if (ccw123 * ccw124 <= 0 && ccw234 * ccw134 <= 0)
	{
		// �� ���� �� ���� ���� �ִ� ���
		if (ccw123 * ccw124 == 0 && ccw234 * ccw134 == 0)
		{
			// �� ������ ��ġ��(�� ������ ������ ��� ����) ���
			if (MAX(x1, x2) >= MIN(x3, x4) && MAX(x3, x4) >= MIN(x1, x2) &&
				MAX(y1, y2) >= MIN(y3, y4) && MAX(y3, y4) >= MIN(y1, y2))
				return true;
			// ��ġ�� �ʴ� ���
			else
				return false;
		}/*
		// �� ���� �� ���� ���� �ִ� ���
		// ���� 12�� �� 3 �Ǵ� 4
		else if (ccw123 * ccw124 == 0)
		{
			int ix, iy;
			if (ccw123 == 0)
			{
				ix = x3;
				iy = y3;
			}
			else
			{
				ix = x4;
				iy = y4;
			}

			// �� 3 �Ǵ� 4�� ���� 12 ���� �ִ� ���
			if ((MAX(x1, x2) >= ix && MIN(x1, x2) <= ix &&
				(MAX(y1, y2) >= iy && MIN(y1, y2) <= iy)))
				return true;
			// �� 3 �Ǵ� 4�� ���� 12 ���� ���� ���� ���
			else
				return false;
		}
		// ���� 34�� �� 1 �Ǵ� 2
		else if (ccw234 * ccw134 == 0)
		{
			int ix, iy;
			if (ccw234 == 0)
			{
				ix = x2;
				iy = y2;
			}
			else
			{
				ix = x1;
				iy = y1;
			}

			// �� 1 �Ǵ� 2�� ���� 34 ���� �ִ� ���
			if ((MAX(x3, x4) >= ix && MIN(x3, x4) <= ix &&
				(MAX(y3, y4) >= iy && MIN(y3, y4) <= iy)))
				return true;
			// �� 1 �Ǵ� 2�� ���� 34 ���� ���� ���� ���
			else
				return false;
		}*/
		else
			return true;
	}
	else return false;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	if (isCross(x1, y1, x2, y2, x3, y3, x4, y4))
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}