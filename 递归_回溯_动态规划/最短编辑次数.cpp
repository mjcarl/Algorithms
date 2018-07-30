#include <iostream>
#include<vector>
#include<string>
using namespace std;

int min(int a, int b, int c);
int main()
{
	string str1, str2;
	cout << "���������ַ�����" << endl;
	cin >> str1 >> str2;
	int M, N, i, j, maxLen = 0;
	M = str1.size();
	N = str2.size();
	vector<vector<int>>dp(M);   //dp[i][j]��ʾstr1[i]��str2[j]���������Ӵ����һ���ַ�������£������Ӵ���ĳ���
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	int tmp = 0;
	for (i = 0; i < M; i++)
	{
		if (str1[i] != str2[0])
		{
			tmp++;
		}
		dp[i][0] = tmp;
	}
	tmp = 0;
	for (j = 0; j < N; j++)
	{
		if (str1[0] != str2[j])
		{
			tmp++;
		}
		dp[0][j] = tmp;
	}
	for (i = 1; i < M; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (str1[i] != str2[j])
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]);
			}
		}
	}
	cout << "���ٱ༭����Ϊ�� " << dp[M - 1][N - 1] << endl;
	return 0;
}

int min(int a, int b, int c)
{
	int tmp;
	tmp = a < b ? a : b;
	tmp = tmp < c ? tmp : c;
	return tmp;
}







