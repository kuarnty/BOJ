//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Node
//{
//	char value;
//	Node* left;
//	Node* right;
//};
//
//void PreorderTraversal(Node* node)
//{
//	if (node == nullptr)
//		return;
//
//	cout << node->value;
//	PreorderTraversal(node->left);
//	PreorderTraversal(node->right);
//}
//
//void InorderTraversal(Node* node)
//{
//	if (node == nullptr)
//		return;
//
//	InorderTraversal(node->left);
//	cout << node->value;
//	InorderTraversal(node->right);
//}
//
//void PostorderTraversal(Node* node)
//{
//	if (node == nullptr)
//		return;
//
//	PostorderTraversal(node->left);
//	PostorderTraversal(node->right);
//	cout << node->value;
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
//	vector<Node> nodes;
//	for (int i = 0; i < n; i++)
//	{
//		Node node = { 'A' + i, nullptr, nullptr };
//		nodes.push_back(node);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		char v, l, r;
//		cin >> v >> l >> r;
//		if (l != '.')
//			nodes[v - 'A'].left = &nodes[l - 'A'];
//		if (r != '.')
//			nodes[v - 'A'].right = &nodes[r - 'A'];
//	}
//
//	PreorderTraversal(&nodes[0]);
//	cout << '\n';
//	InorderTraversal(&nodes[0]);
//	cout << '\n';
//	PostorderTraversal(&nodes[0]);
//
//	return 0;
//}