#include <iostream>
#include <vector>
#include <string>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#endif // !INT_MAX
#ifndef INT_MIN
#define INT_MIN			2147483648
#endif // !INT_MIN

using namespace std;
int n;

struct Node
{
	int level;
	string name;
	vector<Node*> children;
};

bool cmp(Node* a, Node* b)
{
	return a->name < b->name;
}

void print(Node* node)
{
	if (node->name != "")
	{
		for (int i = 0; i < node->level; i++)
			cout << "--";
		cout << node->name << endl;
	}

	if (!node->children.empty())
	{
		//sort(node->children.begin(), node->children.end(), cmp);
		for (int i = 0; i < node->children.size(); i++)
			print(node->children[i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	Node* root = new Node();
	root->level = -1;
	root->name = "";

	while (n--)
	{
		int k;
		cin >> k;
		vector<string> info(k);

		Node* currentParent = root;

		for (int i = 0; i < k; i++)
		{
			string cur;
			cin >> cur;

			Node* next = NULL;
			for (int j = 0; j < currentParent->children.size(); j++)
			{
				if (currentParent->children[j]->name == cur)
				{
					next = currentParent->children[j];
					break;
				}
			}

			// if the cur food name doesn't exist as this parent's child
			if (next == NULL)
			{
				Node* node = new Node();
				node->children = vector<Node*>(0);
				node->level = currentParent->level + 1;
				node->name = cur;
				currentParent->children.push_back(node);
				next = node;
			}

			currentParent = next;
		}
	}

	print(root);

	return 0;
}