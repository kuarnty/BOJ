#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define endl			'\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	map<string, bool> list;

	int n;
	cin >> n;

	string name;
	string log;
	bool logData;

	while (n--)
	{
		cin >> name >> log;
		logData = log == "enter";
		list[name] = logData;
	}

	vector<string> current;

	for (auto i = list.begin(); i != list.end(); i++)
	{
		if (i->second == true)
			current.push_back(i->first);
	}

	sort(current.begin(), current.end());

	for (int i = current.size() - 1; i >= 0; i--)
	{
		cout << current[i] << endl;
	}

	return 0;
}