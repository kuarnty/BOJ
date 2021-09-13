//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int arr[100001];
//
//int BinarySearch(int endIndex, int value)
//{
//	int startIndex = 0;
//	int mid;
//
//	while (endIndex - startIndex >= 0)
//	{
//		mid = (int)((startIndex + endIndex) * 0.5);
//
//		if (arr[mid] == value)
//		{
//			return 1;
//		}
//		else if (value < arr[mid])
//		{
//			endIndex = mid - 1;
//		}
//		else
//		{
//			startIndex = mid + 1;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int N = 0;
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	sort(arr, arr + N);
//
//	int M = 0;
//	scanf("%d", &M);
//
//	for (int i = 0; i < M; i++)
//	{
//		int value = 0;
//		scanf("%d", &value);
//		printf("%d\n", BinarySearch(N, value));
//	}
//
//	return 0;
//}