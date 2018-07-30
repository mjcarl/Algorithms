#include <iostream>
#include<vector>
#include<string>
using namespace std;

int max(int a, int b, int c);
int main()
{
	string str1, str2;
	cout << "���������ַ�����" << endl;
	cin >> str1 >> str2;
	int M, N, i, j;
	M = str1.size();
	N = str2.size();
	vector<vector<int>>dp(M);   //dp[i][j]��ʾstr1[0..i]��str2[0..j]������������г���
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	//�ӵ�һ�п�ʼ��һ����һ��str1[i]==str2[0]����ô��i��ʼ�����Ҳ��Ϊ1.
	//��������λ�õ�dp[i][j]�������������
	//1�����dp[i-1][j]=a������str1[0..i-1]��str2[0..j]��maxDis����ôdp[i][j]Ҳ������a
	//2�����dp[i][j-1]=b������str1[0..i]��str2[0..j-1]��maxDis����ôdp[i][j]Ҳ������b
	//3�����dp[i-1][j-1]=c������str1[0..i-1]��str2[0..j-1]��maxDis����ô���str1[i]==str2[j]����ôdp[i][j]=a+1.
	//���ѡ����������ֵ
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
	cout << "����������г���Ϊ�� " << dp[M - 1][N - 1] << endl;
	return 0;
}

int max(int a, int b, int c)
{
	int t;
	t = a > b ? a : b;
	t = t > c ? t : c;
	return t;
}