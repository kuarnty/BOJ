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
//		// �д� ���� (ó������ ���ڰ� ��ġ�� ����)
//		if (reading)
//		{
//			if (document[documentIndex] == word[wordIndex])
//			{
//				// �ش� ��ġ�� �ܾ��� ������ ������ ��� -> ī��Ʈ�ϰ� �б� ����
//				if (wordIndex == strlen(word) - 1)
//				{
//					count++;
//					reading = false;
//					wordIndex = 0;
//				}
//				// ����ؼ� ���ڸ� �о� ���� �ϴ� ���
//				else
//				{
//					wordIndex++;
//				}
//			}
//			// ã�� �ܾ �ƴ� ��� -> �б� ���� (�´ٸ� ���� �������� �ɸ��� ��)
//			// �̶� ó�� ���ڰ� �¾Ҵ� ��ġ�� �ٷ� �������� �ٽ� ã�ƺ��� �� (�̶��� ���� �� �ֱ� ������)
//			// ex) aaab ���� aab�� ã�� ��� aa'a'b ���� Ʋ���� a'a'ab ���� �ٽ� ã�ƾ� ��
//			else
//			{
//				documentIndex -= wordIndex;
//				wordIndex = 0;
//				reading = false;
//			}
//		}
//		// �а� ���� �ʴ� ��� (�ܾ��� ù ���ڿ� �´� ��츦 ã�ƾ� ��)
//		else
//		{
//			// �ܾ��� ù ���ڿ� �´� ���ڸ� ã�� -> �б� ����
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
//			// ���� ������ ���� ���ڷ� �ѱ�
//		}
//
//		documentIndex++;
//	}
//
//	cout << count;
//
//	return 0;
//}