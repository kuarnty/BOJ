//#include <iostream>
//#include <vector>
//
//#define MAX 100000
//
//using namespace std;
//
//struct Node
//{
//	int value;
//	int parent;
//	vector<Node*> nodes;
//};
//
//bool visited[MAX];
//vector<Node> nodes(MAX);
//vector<int> parents(MAX);
//
//void dfs(Node* node, Node* parent)
//{
//	if (node == nullptr)
//		return;
//
//	visited[node->value] = true;
//	if (parent != nullptr)
//	{
//		node->parent = parent->value;
//	}
//
//	for (int i = 0; i < node->nodes.size(); i++)
//	{
//		if (!visited[node->nodes[i]->value])
//		{
//			dfs(node->nodes[i], node);
//		}
//	}
//	return;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	int count = n;
//	for (int i = 0; i < count; i++)
//	{
//		nodes[i + 1].value = i + 1;
//	}
//
//	while (--n)
//	{
//		int a, b;
//		cin >> a >> b;
//		nodes[a].nodes.push_back(&(nodes[b]));
//		nodes[b].nodes.push_back(&(nodes[a]));
//	}
//
//	dfs(&(nodes[1]), nullptr);
//
//	for (int i = 1; i < count; i++)
//	{
//		cout << nodes[i + 1].parent << '\n';
//	}
//
//	return 0;
//}