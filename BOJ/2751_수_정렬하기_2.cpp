//#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
//
//using namespace std;
//
//void Merge(int* arr, int* sortedArr, int begin, int middle, int end)
//{
//	int sortedIndex = begin;
//	int left = begin;
//	int right = middle + 1;
//
//
//	while (left <= middle && right <= end)
//	{
//		if (arr[left] < arr[right])
//		{
//			sortedArr[sortedIndex] = arr[left++];
//		}
//		else
//		{
//			sortedArr[sortedIndex] = arr[right++];
//		}
//
//		sortedIndex++;
//	}
//
//	// 왼쪽이 오른쪽보다 먼저 끝에 도달한 경우 (왼쪽이 먼저 모두 정렬된 경우)
//	if (left > middle)
//	{
//		while (right <= end)
//		{
//			sortedArr[sortedIndex++] = arr[right++];
//		}
//	}
//	// 오른쪽이 왼쪽보다 먼저 끝에 도달한 경우 (오른쪽이 먼저 모두 정렬된 경우)
//	if (right > end)
//	{
//		while (left <= middle)
//		{
//			sortedArr[sortedIndex++] = arr[left++];
//		}
//	}
//
//	for (int k = begin; k <= end; k++)
//	{
//		arr[k] = sortedArr[k];
//	}
//}
//
//void MergeSort(int* arr, int* sortedArr, int begin, int end)
//{
//	int middle;
//	if (begin < end)
//	{
//		middle = (begin + end) / 2;
//		MergeSort(arr, sortedArr, begin, middle);
//		MergeSort(arr, sortedArr, middle + 1, end);
//		Merge(arr, sortedArr, begin, middle, end);
//	}
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//	int N;
//	cin >> N;
//
//	int* arr = new int[N];
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i];
//	}
//
//	int* sortedArr = new int[N];
//	MergeSort(arr, sortedArr, 0, N - 1);
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << arr[i] << '\n';
//	}
//
//	return 0;
//}