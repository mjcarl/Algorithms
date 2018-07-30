#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minUse(int arr[], int kind, int n);
int main()
{
	int sum = 10, m;
	int arr[3] = { 2,3,5 }, kind = 3;
	cout << "输入总金额： ";
	cin >> sum;
	m = minUse(arr, kind, sum);

	cout << "最小张数为： "<< m<< endl;;
	return 0;
}

int min(int a, int b)
{
	int tmp;
	tmp = a < b ? a : b;
	return tmp;

}

int minUse(int arr[], int kind, int n)
{
	int i, j, max = 99999;
	vector<vector<int>>dp(kind);
	for (i = 0; i < kind; i++)
	{
		dp[i].resize(n + 1);
	}
	for (i = 0; i < kind; i++)
	{
		for (j = 1; j <= n; j++)
		{
			dp[i][j] = max;
		}
	}
	for (i = 0; i <kind; i++)   //第一列全为0，剩下的全为max
		dp[i][0] = 0;
	for (j = 1; j <= n; j++)
	{
		dp[0][j] = max;
		if (j - arr[0] >= 0 && dp[0][j - arr[0]] != max)
		{
			dp[0][j] = dp[0][j - arr[0]] + 1;   //计算第一行数据
		}
	}
	int left = 0;
	for (i = 1; i < kind; i++)
	{
		for (j = 1; j <= n; j++)
		{
			left = max;
			if (j - arr[i] >= 0 && dp[i][j - arr[i]] != max)   //dp[i][j] = min{dp[i-1][j], dp[i][j-arr[i]]+1}
				left = dp[i][j - arr[i]] + 1;
			dp[i][j] = min(left, dp[i - 1][j]);
			cout << " i= " << i << " j= " << j << " dp= " << dp[i][j]<< endl;
		}
		cout << endl;
	}
	return dp[kind-1][n] != max ? dp[kind-1][n] : -1;
}
