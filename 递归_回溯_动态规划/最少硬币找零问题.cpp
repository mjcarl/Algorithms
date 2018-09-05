#include<bits/stdc++.h>
using namespace std;

int dp[10][1000] = { 0 };  //dp[i][j]可用第 0，1，.... i 枚硬币 对 金额为 j 的钱 进行找钱 所需要的最少硬币数。
const int inf = 99999;
#define  min(x,y)   (x)<(y)?(x):(y)  

int main()
{
	int N, sum;
	cin >> N >> sum;
	vector<int>cost(N+1, 0);
	int i, j;
	for (i = 1; i <= N; i++)  //此处i要到N
	{
		cin >> cost[i];
	}
	for (j = 0; j <= sum; j++)
	{
		dp[0][j] = inf;  //初始化第一行为inf
	}
	for (i = 0; i <= N; i++) 
	{
		dp[i][0] = 0;   //第一列都为0，不需要硬币
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			if (j >= cost[i])
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - cost[i]] + 1);  //注意，此处第二项的i不减1，因为i表示可以用到第i个硬币，+1是找零硬币个数+1
			}
			else
			{
				dp[i][j] = dp[i - 1][j];  //第i个硬币面值大于j，用不上
			}
		}
	}
	cout << "dp[][]:" << endl;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[N][sum] << endl;
	return 0;
}