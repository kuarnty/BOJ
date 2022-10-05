#include <iostream>
#include <vector>

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
	int n, p;
	cin >> n >> p;

	Stack line[6];
	
	int m = 0;

	while (n--)
	{
		int l, f;
		cin >> l >> f;
		l--;

		while (line[l].Top() > f)
		{
			line[l].Pop();
			m++;
		}

		if (line[l].Top() != f)
		{
			line[l].Push(f);
			m++;
		}
	}

	cout << m;

	return 0;
}