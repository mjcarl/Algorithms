#include<bits/stdc++.h>
using namespace std;

int dp[10][1000] = { 0 };  //dp[i][j]���õ� 0��1��.... i öӲ�� �� ���Ϊ j ��Ǯ ������Ǯ ����Ҫ������Ӳ������
const int inf = 99999;
#define  min(x,y)   (x)<(y)?(x):(y)  

int main()
{
	int N, sum;
	cin >> N >> sum;
	vector<int>cost(N+1, 0);
	int i, j;
	for (i = 1; i <= N; i++)  //�˴�iҪ��N
	{
		cin >> cost[i];
	}
	for (j = 0; j <= sum; j++)
	{
		dp[0][j] = inf;  //��ʼ����һ��Ϊinf
	}
	for (i = 0; i <= N; i++) 
	{
		dp[i][0] = 0;   //��һ�ж�Ϊ0������ҪӲ��
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			if (j >= cost[i])
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - cost[i]] + 1);  //ע�⣬�˴��ڶ����i����1����Ϊi��ʾ�����õ���i��Ӳ�ң�+1������Ӳ�Ҹ���+1
			}
			else
			{
				dp[i][j] = dp[i - 1][j];  //��i��Ӳ����ֵ����j���ò���
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