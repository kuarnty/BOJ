//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int lower_binary(int* arr, int target, int size)
//{
//	int mid, start, end;
//	start = 0, end = size - 1;
//
//	while (end > start)
//	{
//		mid = (start + end) / 2;
//		if (arr[mid] >= target)
//			end = mid;
//		else start = mid + 1;
//	}
//	return end;
//}
//
//int upper_binary(int* arr, int target, int size)
//{
//	int mid, start, end;
//	start = 0, end = size - 1;
//
//	while (end > start)
//	{
//		mid = (start + end) / 2;
//		if (arr[mid] > target)
//			end = mid;
//		else start = mid + 1;
//	}
//	return end;
//}
//
//int main(void)
//{
//	int n, m, temp, target, lower, upper;
//
//	scanf("%d", &n);
//	int* m_arr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &m_arr[i]);
//	}
//	sort(m_arr, m_arr + n);
//
//	scanf("%d", &m);
//	int* arr = new int[m];
//	int* result = new int[m];
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[i]);
//		result[i] = 0;
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		lower = lower_binary(m_arr, arr[i], n);
//		upper = upper_binary(m_arr, arr[i], n);
//		// lower는 가장 처음으로 나오는 위치, upper는 마지막으로 나오는 위치+1을 반환하므로
//		// 만약 개수가 0개라면 두 경우 모두 찾지 못하고 start = mid + 1 을 통해 
//		// target보다 큰 값의 위치를 똑같이 반환함 (없으면 size만큼의 값을 반환함) 따라서 upper - lower == 0이 됨
//		// 
//		// 그런데, 개수가 1개일 경우에도 lower == upper 이므로 개수가 0개일때와 같은 결과가 나옴
//		// 그래서 upper++을 해 줘야 함
//		// 그러나, 이렇게 할 경우 개수가 1개가 아니어도 배열의 맨 뒤에 1개 이상의 target이 있을 경우 아래의 조건을 만족하는데
//		// 이 경우에는 upper 값이 어쩔 수 없이 end()-1을 가리킬 수 밖에 없어서 1개일 때와 마찬가지로 upper++을 해 줘야 한다.
//		// 즉, 아래 조건을 만족하는 두 경우(개수가 단 1개일 경우, 맨 마지막에 해당하는 값을 카운트하는 경우)가 모두 upper++ 작업을 필요로한다.
//		if (upper == n - 1 && m_arr[n - 1] == arr[i])
//			upper++;
//		result[i] = upper - lower;
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		printf("%d ", result[i]);
//	}
//	return 0;
//}
