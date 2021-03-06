//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//#include <string.h>
//
//using namespace std;
//
//int dy[4] = { 1,-1,0,0 };
//int dx[4] = { 0,0,1,-1 };
//int M, N, K;
//int arr[50][50] = { 0 };
//int visited[50][50] = { 0 };
//
//void dfs(int x, int y) 
//{
//    for (int i = 0; i < 4; i++) 
//    {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
//            continue;
//
//        if (arr[nx][ny] && !visited[nx][ny]) 
//        {
//            visited[nx][ny]++;
//            dfs(nx, ny);
//        }
//    }
//}
//
//int main()
//{
//    int T, x, y;
//    scanf("%d", &T);
//
//    for (int testCase = 0; testCase < T; testCase++) 
//    {
//        scanf("%d%d%d", &M, &N, &K);
//
//        memset(arr, 0, sizeof(arr));
//        memset(visited, 0, sizeof(visited));
//
//        int count = 0;
//
//        for (int i = 0; i < K; i++) 
//        {
//            scanf("%d%d", &x, &y);
//            arr[x][y] = 1;
//        }
//
//        for (int i = 0; i < M; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                if (arr[i][j] && !visited[i][j])
//                {
//                    count++;
//                    visited[i][j]++;
//                    dfs(i, j);
//                }
//            }
//        }
//        cout << count << endl;
//    }
//    return 0;
//}
