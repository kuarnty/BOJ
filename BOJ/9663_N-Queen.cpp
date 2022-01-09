//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//int n;
//int cases = 0;
//int board[15];
//
////
////void Check(vector<vector<bool>> board, int count)
////{
////	if (count == n)
////	{
////		cases++;
////		return;
////	}
////
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < n; j++)
////		{
////			if (!board[i][j])
////			{
////				vector<vector<bool>> newBoard = board;
////				newBoard[i][j] = true;
////
////				// collumn
////				for (int k = 0; k < n; k++)
////				{
////					newBoard[i][k] = true;
////				}
////				// row
////				for (int k = 0; k < n; k++)
////				{
////					newBoard[k][j] = true;
////				}
////				int k;
////				// up left
////				k = MIN(i, j);
////				for (int x, y = 0; k > 0; k--)
////				{
////					x = i;
////					y = j;
////					newBoard[--x][--y] = true;
////				}
////				// up right
////				k = MIN(i, n - j - 1);
////				for (int x, y = 0; k > 0; k--)
////				{
////					x = i;
////					y = j;
////					newBoard[--x][++y] = true;
////				}
////				// down left
////				k = MIN(n - i - 1, j);
////				for (int x, y = 0; k > 0; k--)
////				{
////					x = i;
////					y = j;
////					newBoard[++x][--y] = true;
////				}
////				// down right
////				k = MIN(n - i - 1, n - j - 1);
////				for (int x, y = 0; k > 0; k--)
////				{
////					x = i;
////					y = j;
////					newBoard[++x][++y] = true;
////				}
////
////				Check(newBoard, count + 1);
////			}
////		}
////	}
////}
//
//bool Check(int index)
//{
//	for (int i = 0; i < index; i++)
//	{
//		if ((board[index] == board[i]) || (abs(board[index] - board[i]) == (index - i)))
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//void Mate(int index)
//{
//	if (index == n)
//	{
//		cases++;
//		return;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		board[index] = i;
//		if (Check(index))
//		{
//			Mate(index + 1);
//			// no need to initialize board
//		}
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	cin >> n;
//
//	Mate(0);
//
//	cout << cases;
//
//	return 0;
//}