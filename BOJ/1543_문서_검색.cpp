//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//char document[2501];
//char word[51];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin.getline(document, 2501);
//	cin.getline(word, 51);
//
//	int documentIndex = 0;
//	int wordIndex = 0;
//	int count = 0;
//	bool reading = false;
//
//	while (documentIndex < strlen(document))
//	{
//		// 읽는 도중 (처음으로 문자가 일치한 다음)
//		if (reading)
//		{
//			if (document[documentIndex] == word[wordIndex])
//			{
//				// 해당 위치가 단어의 마지막 글자인 경우 -> 카운트하고 읽기 종료
//				if (wordIndex == strlen(word) - 1)
//				{
//					count++;
//					reading = false;
//					wordIndex = 0;
//				}
//				// 계속해서 글자를 읽어 봐야 하는 경우
//				else
//				{
//					wordIndex++;
//				}
//			}
//			// 찾는 단어가 아닌 경우 -> 읽기 종료 (맞다면 이전 루프에서 걸리게 됨)
//			// 이때 처음 글자가 맞았던 위치의 바로 다음부터 다시 찾아봐야 함 (이때는 맞을 수 있기 때문에)
//			// ex) aaab 에서 aab를 찾는 경우 aa'a'b 에서 틀리면 a'a'ab 부터 다시 찾아야 함
//			else
//			{
//				documentIndex -= wordIndex;
//				wordIndex = 0;
//				reading = false;
//			}
//		}
//		// 읽고 있지 않는 경우 (단어의 첫 글자와 맞는 경우를 찾아야 함)
//		else
//		{
//			// 단어의 첫 글자와 맞는 글자를 찾음 -> 읽기 시작
//			if (document[documentIndex] == word[wordIndex])
//			{
//				if (strlen(word) == 1)
//				{
//					count++;
//				}
//				else
//				{
//					reading = true;
//					wordIndex++;
//				}
//			}
//			// 맞지 않으면 다음 글자로 넘김
//		}
//
//		documentIndex++;
//	}
//
//	cout << count;
//
//	return 0;
//}