//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//static int cnt = 0;
//
//struct Computer
//{
//	bool infected = false;
//	vector<Computer*> connected;
//};
//
//void infection(Computer* c)
//{
//	if (c->infected)
//	{
//		cnt++;
//		for (int i = 0; i < c->connected.size(); i++)
//		{
//			if (!(c->connected[i]->infected))
//			{
//				c->connected[i]->infected = true;
//				infection(c->connected[i]);
//			}
//			else
//			{
//				continue;
//			}
//		}
//	}
//	else
//	{
//		return;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, c;
//	cin >> n >> c;
//	vector<Computer> v(101);
//
//	for (int i = 0; i < c; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		v[a].connected.push_back(&v[b]);
//		v[b].connected.push_back(&v[a]);
//	}
//
//	v[1].infected = true;
//
//	infection(&v[1]);
//
//	cout << --cnt;
//
//	return 0;
//}