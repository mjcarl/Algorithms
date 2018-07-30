#include <iostream>
#include<vector>
#include<string>
using namespace std;

int min(int a, int b, int c);
int main()
{
	string str1, str2;
	cout << "输入两个字符串：" << endl;
	cin >> str1 >> str2;
	int M, N, i, j, maxLen = 0;
	M = str1.size();
	N = str2.size();
	vector<vector<int>>dp(M+1);   //dp[i][j]表示str1[i]与str2[j]当作公共子串最后一个字符的情况下，公共子串最长的长度
	for (i = 0; i <= M; i++)
		dp[i].resize(N+1);

	for (i = 0; i <= M; i++)
	{
		dp[i][0] = i;
	}
	for (j = 0; j <= N; j++)
	{
		dp[0][j] = j;
	}
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (str1[i-1] != str2[j-1])
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]);
			}
		}
	}
	cout << "最少编辑次数为： " << dp[M][N] << endl;
	return 0;
}

int min(int a, int b, int c)
{
	int tmp;
	tmp = a < b ? a : b;
	tmp = tmp < c ? tmp : c;
	return tmp;
}







