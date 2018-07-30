#include <iostream>
#include<vector>
#include<string>
using namespace std;

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
	//��һ��dp[0..M-1][0]�����str1[i]==str2[0]����dp[i][0]=1������Ϊ0����һ��ͬ��
	//����dp[i][j]��˵�����str1[i]!=str2[j]�����䵱�������Ӵ������һλ�ǲ����ܵģ���dp[i][j]=0;
	//���str1[i]==str2[j]����dp[i][j]=dp[i-1][j-1]+1;
	//ȡdp��������ֵ��Ϊ����
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
	cout << "������Ӵ��ĳ���Ϊ�� " << maxLen << endl;
	return 0;
}

