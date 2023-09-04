#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ascendingVector = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> descendingVector = { 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> v;
	for (int i = 0; i < 8; i++)
	{
		int value;
		cin >> value;
		v.push_back(value);
	}
	if (v == ascendingVector)
		cout << "ascending";
	else if (v == descendingVector)
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}