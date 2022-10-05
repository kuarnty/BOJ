#include <iostream>

#define MAXSIZE	20000
#define endl	'\n'

using namespace std;

class Dequeue
{
public:
	int arr[MAXSIZE];
	int front;
	int back;

	Dequeue()
	{
		front = MAXSIZE / 2;
		back = front - 1;
	}

	void push_front(int x)
	{
		arr[--front] = x;
	}

	void push_back(int x)
	{
		arr[++back] = x;
	}

	int pop_front()
	{
		if (empty())
			return -1;
		else
			return arr[front++];
	}

	int pop_back()
	{
		if (empty())
			return -1;
		else
			return arr[back--];
	}

	int size()
	{
		return back - front + 1;
	}

	int empty()
	{
		if (front > back)
			return 1;
		else
			return 0;
	}

	int peak_front()
	{
		if (empty())
			return -1;
		else
			return arr[front];
	}

	int peak_back()
	{
		if (empty())
			return -1;
		else
			return arr[back];
	}
};

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Dequeue dq;

	int n;
	cin >> n;

	string command;
	int num;

	while (n--)
	{
		cin >> command;

		if (command == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front")
			cout << dq.pop_front() << endl;
		else if (command == "pop_back")
			cout << dq.pop_back() << endl;
		else if (command == "size")
			cout << dq.size() << endl;
		else if (command == "empty")
			cout << dq.empty() << endl;
		else if (command == "front")
			cout << dq.peak_front() << endl;
		else if (command == "back")
			cout << dq.peak_back() << endl;
		else
			continue;
	}

	return 0;
}

//#include <iostream>
//#include <deque>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	deque<int> q;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		if (s == "pop_front")
//		{
//			if (q.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", q.front());
//				q.pop_front();
//			}
//		}
//		else if (s == "pop_back")
//		{
//			if (q.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", q.back());
//				q.pop_back();
//			}
//		}
//		else if (s == "size")
//		{
//			printf("%d\n", q.size());
//		}
//		else if (s == "empty")
//		{
//			printf("%d\n", q.empty() ? 1 : 0);
//		}
//		else if (s == "front")
//		{
//			printf("%d\n", q.empty() ? -1 : q.front());
//		}
//		else if (s == "back")
//		{
//			printf("%d\n", q.empty() ? -1 : q.back());
//		}
//		else if (s == "push_front")
//		{
//			int m;
//			cin >> m;
//			q.push_front(m);
//		}
//		else if (s == "push_back")
//		{
//			int m;
//			cin >> m;
//			q.push_back(m);
//		}
//	}
//}