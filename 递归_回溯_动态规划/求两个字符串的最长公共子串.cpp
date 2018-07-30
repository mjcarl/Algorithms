#include <iostream>
#include<vector>
#include<string>
using namespace std;

int max(int a, int b, int c);
int main()
{
	string str1, str2;
	cout << "输入两个字符串：" << endl;
	cin >> str1 >> str2;
	int M, N, i, j;
	M = str1.size();
	N = str2.size();
	vector<vector<int>>dp(M);   //dp[i][j]表示str1[0..i]与str2[0..j]的最长公共子序列长度
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	//从第一列开始，一旦有一个str1[i]==str2[0]，那么从i开始后面的也都为1.
	//对于其他位置的dp[i][j]，分三种情况：
	//1、如果dp[i-1][j]=a，代表str1[0..i-1]与str2[0..j]的maxDis，那么dp[i][j]也可能是a
	//2、如果dp[i][j-1]=b，代表str1[0..i]与str2[0..j-1]的maxDis，那么dp[i][j]也可能是b
	//3、如果dp[i-1][j-1]=c，代表str1[0..i-1]与str2[0..j-1]的maxDis，那么如果str1[i]==str2[j]，那么dp[i][j]=a+1.
	//最后选三者中最大的值
	int tmp = 0;
	for (i = 0; i < M; i++)
	{
		if (tmp == 1)
			dp[i][0] = 1;
		else if (str1[i] == str2[0])
		{
			dp[i][0] = 1;
			tmp = 1;
		}
	}
	for (j = 0; j < N; j++)
	{
		if (tmp == 1)
			dp[0][j] = 1;
		else if (str1[0] == str2[j])
		{
			dp[0][j] = 1;
			tmp = 1;
		}
	}
	for (i = 1; i < M; i++)
	{
		for (j = 1; j < N; j++)
		{
			tmp = 0;
			if (str1[i] == str2[j])
				tmp = 1;
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + tmp);
		}
	}
	cout << "最长公共子序列长度为： " << dp[M - 1][N - 1] << endl;
	return 0;
}

int max(int a, int b, int c)
{
	int t;
	t = a > b ? a : b;
	t = t > c ? t : c;
	return t;
}