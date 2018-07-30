#include <iostream>
#include<vector>
#include<string>
using namespace std;

int max(int a, int b);
int min(int a, int b);
int main()
{
	int M, N, i, j, maxLen = 0;
	cout << "输入地下城的大小： ";
	cin >> M;
	cin >> N;
	cout << "输入每个城的血药或消耗： " << endl;
	vector<vector<int>>arr(M);   
	for (i = 0; i < M; i++)
		arr[i].resize(N);
	vector<vector<int>>dp(M);   //dp[i][j]表示如果骑士要走到(i,j)，并且从该位置走最优路径到最下面，所至少有的血量
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	int tmp;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	dp[M - 1][N - 1] = max(1-arr[M-1][N-1],1);
	for (j = N - 2; j >= 0; j--)
	{
		dp[M - 1][j] = max(dp[M - 1][j + 1] - arr[M - 1][j], 1);
	}
	for (i = M - 2; i >= 0; i--)
	{
		dp[i][N - 1] = max(dp[i + 1][N - 1] - arr[i][N - 1], 1);
	}
	for (j = N - 2; j >= 0; j--)  //倒序
	{
		for (i = M - 2; i >= 0; i--)
		{
			dp[i][j] = max(min(dp[i][j + 1] - arr[i][j], dp[i + 1][j] - arr[i][j]), 1);
		}
	}
	cout << "最少进城血量为： " << dp[0][0] << endl;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
