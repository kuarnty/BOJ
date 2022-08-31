// TODO: 

#include <iostream>
#include <vector>
#include <queue>
//strlen은 cstring에 있다 쓰레기같은거

using namespace std;

struct Flower
{
	int m1;
	int d1;
	int m2;
	int d2;
};

struct Compare
{
	bool operator()(const Flower& a, const Flower& b)
	{
		if (a.m1 == b.m1)
		{
			if (a.d1 == b.d1)
			{
				if (a.m2 == b.m2)
				{
					return a.d2 < b.d2;
				}
				else
				{
					return a.m2 < b.m2;
				}
			}
			else
			{
				return a.d1 > b.d1;
			}
		}
		else
		{
			return a.m1 > b.m1;
		}
	}
};

int compareDay(int m1, int d1, int m2, int d2)
{
	if (m1 == m2)
	{
		if (d1 == d2)
			return 0;
		else
			return d1 < d2 ? -1 : 1;
	}
	else
		return m1 < m2 ? -1 : 1;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<Flower, vector<Flower>, Compare> flowers;
	for (int i = 0; i < n; i++)
	{
		int m1, m2, d1, d2;
		cin >> m1 >> d1 >> m2 >> d2;

		if (m2 < 3 || (m2 == 3 && d2 == 1))
			continue;
		if (m1 >= 12)
			continue;

		flowers.push({ m1, d1, m2, d2 });
	}

	if (flowers.empty())
	{
		cout << 0;
		return 0;
	}

	Flower f = flowers.top();
	flowers.pop();

	Flower current = f;
	int lastMonth = f.m2;
	int lastDay = f.m1;

	int count = 1;

	while (!flowers.empty())
	{
		f = flowers.top();
		flowers.pop();

		if (lastMonth >= 12)
			break;

		if (compareDay(f.m1, f.d1, current.m2, current.d2) > 0)
		{
			break;
		}
		else if (compareDay(f.m2, f.d2, current.m2, current.d2) <= 0)
		{
			continue;
		}
		else if (compareDay(f.m1, f.d1, lastMonth, lastDay) > 0)
		{
			flowers.push(f);
			lastMonth = current.m2;
			lastDay = current.d2;
			count++;
		}
		// 일단 f1이 last 이하(포함)임이 보장된 상태 (즉, 추가 가능한 상태)
		// f2도 current보다 큰(같지 않음) 상태이므로 current를 업데이트
		else
		{
			// current.m1, current.d1 은 업데이트하는 의미가 없음. 어차피 비교 안함
			current.m2 = f.m2;
			current.d2 = f.d2;
		}

		if (flowers.empty() && compareDay(current.m2, current.d2, lastMonth, lastDay) != 0)
		{
			lastMonth = current.m2;
			lastDay = current.d2;
			count++;
		}
	}

	if (lastMonth < 12)
		cout << 0;
	else
		cout << count;

	//while (!flowers.empty())
	//{
	//	Flower f = flowers.top();
	//	flowers.pop();
	//	cout << f.m1 << "-" << f.m2 << " " << f.m2 << "-" << f.d2 << "\n";
	//}

	return 0;
}