#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

struct Point
{
	ll x, y;
};

vector<Point> p;

int N;

// Cross product of p1p2, p2p3
// Result
//			> 0		CCW
//			< 0		CW
//			= 0		Parallel
ll CCW(Point p1, Point p2, Point p3)
{
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
}

bool CompareYCoordinate(Point p1, Point p2)
{
	if (p1.y == p2.y)
		return p1.x < p2.x;
	else
		return p1.y < p2.y;
}

// sort by CCW degree (from x-axis)
bool CompareDegree(Point p1, Point p2)
{
	ll value = CCW(p[0], p1, p2);
	// if parallel, consider the near point as front point
	if (value == 0)
	{
		if (p1.y != p2.y)
			return p1.y < p2.y;
		else
			return p1.x < p2.x;
	}
	return value > 0;
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> N;
	p = vector<Point>(N);

	for (int i = 0; i < N; i++)
		cin >> p[i].x >> p[i].y;

	sort(p.begin(), p.end(), CompareYCoordinate);
	sort(p.begin() + 1, p.end(), CompareDegree);

	stack<Point> s;
	s.push(p[0]);
	s.push(p[1]);

	// Check all points in order of CCW
	for (int i = 2; i < N; i++)
	{
		while (s.size() >= 2)
		{
			// take 2 points from stack (pop p2, and just pick p1 => we need to push back p2 later)
			Point p2 = s.top();
			s.pop();
			Point p1 = s.top();

			int ccw = CCW(p1, p2, p[i]);
			// when the two points(p1, p2) and current point(p[i]) is in CCW (i.e. convex)
			if (ccw > 0)
			{
				// then, push (poped)p2 back on stack, and break.
				s.push(p2);
				break;
			}
			// or, (i.e. three points are in parellel, or CW) ignore the p2(this is in the convex),
			// and take p2(it was p1 before) and p1 again
		}

		// poped point(p2) is pushed back,
		// then push current point[2] on stack
		// i.e. current point is valid (at least until current point)
		s.push(p[i]);
	}
	cout << s.size();

	return 0;
}