#include<bits/stdc++.h>
using namespace std;

#define  V 1500  
unsigned int dp[10][V] = { 0 };   //dp[i][m]表示前i件物品恰放入一个重量为m的背包可以获得的最大价值
unsigned int weight[10];
unsigned int value[10];
#define  max(x,y)   (x)>(y)?(x):(y)  

int main()
{
	int N, cap;
	cin >> N;  //物品个数
	cin >> cap;  //背包容量
	int i, j;
	for (i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i];
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= cap; j++)
		{
			if (weight[i] <= j)
			{
				//1、这时候背包容量不足以放下第 i 件物品，只能选择不拿；  2、这时背包容量可以放下第 i 件物品，我们就要考虑拿这件物品是否能获取更大的价值
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);  //只看第i件物品放不放
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << "dp[][]:" << endl;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= cap; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "max_value = " << dp[N][cap] << endl;
	return 0;
}