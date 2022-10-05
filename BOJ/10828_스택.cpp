#include <iostream>
#include <string>

using namespace std;

class Stack
{
	int size;
	int capacity;
	int* arr;

public:
	Stack()
	{
		capacity = 4;
		arr = new int[capacity];
		size = 0;
	}

	void Push(int element)
	{
		if (size >= capacity)
			Resize(capacity * 2);
		arr[size++] = element;
	}

	void Resize(int newSize)
	{
		arr = (int*)realloc(arr, sizeof(int) * newSize);
		capacity = newSize;
	}

	int Pop()
	{
		if (size == 0)
			return -1;
		else
			return arr[--size];
	}

	int Size()
	{
		return size;
	}

	int empty()
	{
		return size == 0 ? 1 : 0;
	}

	int Top()
	{
		if (size == 0)
			return -1;
		else
			return arr[size - 1];
	}
};

int main()
{
	int n;
	cin >> n;

	Stack s;

	while (n--)
	{
		string command;
		int number;

		cin >> command;

		if (command == "push")
		{
			cin >> number;
			s.Push(number);
		}
		else if (command == "pop")
		{
			cout << s.Pop() << endl;
		}
		else if (command == "size")
		{
			cout << s.Size() << endl;;
		}
		else if (command == "empty")
		{
			cout << s.empty() << endl;
		}
		else if (command == "top")
		{
			cout << s.Top() << endl;
		}
		else
			continue;
	}

	return 0;
}

//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	stack<int> k;
//	for (int i = 0; i < n; i++)
//	{
//		string s;
//		cin >> s;
//
//		if (s == "pop")
//		{
//			if (k.empty())
//			{
//				printf("%d\n", -1);
//			}
//			else
//			{
//				printf("%d\n", k.top());
//				k.pop();
//			}
//		}
//		else if (s == "size")
//		{
//			printf("%d\n", k.size());
//		}
//		else if (s == "empty")
//		{
//			printf("%d\n", k.empty() ? 1 : 0);
//		}
//		else if (s == "top")
//		{
//			printf("%d\n", k.empty() ? -1 : k.top());
//		}
//		else // s== "push"
//		{
//			int m;
//			cin >> m;
//			k.push(m);
//		}
//	}
//}