#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	cout << "输入两个字符串：" << endl;
	cin >> str1 >> str2;
	int M, N, i, j, maxLen = 0;
	M = str1.size();
	N = str2.size();
	vector<vector<int>>dp(M);   //dp[i][j]表示str1[i]与str2[j]当作公共子串最后一个字符的情况下，公共子串最长的长度
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	//第一列dp[0..M-1][0]，如果str1[i]==str2[0]，则dp[i][0]=1，否则为0；第一行同理
	//对于dp[i][j]来说：如果str1[i]!=str2[j]，则其当作公共子串的最后一位是不可能的，置dp[i][j]=0;
	//如果str1[i]==str2[j]，令dp[i][j]=dp[i-1][j-1]+1;
	//取dp数组的最大值作为返回
	for (i = 0; i < M; i++)
	{
		if (str1[i] == str2[0])
			dp[i][0] = 1;
	}
	for (j = 0; j < N; j++)
	{
		if (str1[0] == str2[j])
			dp[0][j] = 1;
	}
	for (i = 1; i < M; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = 0;
			maxLen = maxLen > dp[i][j] ? maxLen : dp[i][j];
		}
	}
	cout << "最长公共子串的长度为： " << maxLen << endl;
	return 0;
}

