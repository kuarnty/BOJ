#include <iostream>

#define MAXSIZE	2000000
#define endl	'\n'

using namespace std;

class Queue
{
private:
	int capacity = MAXSIZE;
	int arr[MAXSIZE];
	int front;
	int back;

public:
	Queue()
	{
		capacity = MAXSIZE;
		front = -1;
		back = -1;
	}

	void Push(int e)
	{
		//if (Size() >= capacity)
		//	Resize(capacity * 2);

		//if (++back >= capacity)
		//	back -= capacity;
		//arr[back] = e;
		arr[++back] = e;
	}

	int Pop()
	{
		if (Empty())
			return -1;
		else
		{
			//if (++front >= capacity)
			//	front -= capacity;
			//int r = arr[front];
			//return r;
			return arr[++front];
		}
	}

	int Size()
	{
		//int r = back - front;
		//if (r < 0)
		//	return r + capacity;
		//else if (r >= capacity)
		//	return r - capacity;
		//else
		//	return r;
		return back - front;
	}

	int Empty()
	{
		if (Size() == 0)
			return 1;
		else
			return 0;
	}

	int Front()
	{
		if (Empty())
			return -1;
		else
		{
			//if (front + 1 >= capacity)
			//	return arr[(front + 1) - capacity];
			//else
				return arr[front + 1];
		}
	}

	int Back()
	{
		if (Empty())
			return -1;
		else
			return arr[back];
	}

	//private:
	//	void Resize(int newSize)
	//	{
	//		int* newArr = new int[newSize];
	//		for (int i = 1; i < capacity; i++)
	//			newArr[i] = arr[++front];
	//		front = 0;
	//		back = capacity;
	//		capacity = newSize;
	//		delete(arr);
	//		arr = newArr;
	//	}
};

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Queue q;

	int n;
	cin >> n;

	string command;
	int num;

	while (n--)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> num;
			q.Push(num);
		}
		else if (command == "pop")
			cout << q.Pop() << endl;
		else if (command == "size")
			cout << q.Size() << endl;
		else if (command == "empty")
			cout << q.Empty() << endl;
		else if (command == "front")
			cout << q.Front() << endl;
		else if (command == "back")
			cout << q.Back() << endl;
		else
			continue;
	}

	return 0;
}