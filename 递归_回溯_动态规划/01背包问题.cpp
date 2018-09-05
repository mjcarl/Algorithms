#include<bits/stdc++.h>
using namespace std;

#define  V 1500  
unsigned int dp[10][V] = { 0 };   //dp[i][m]��ʾǰi����Ʒǡ����һ������Ϊm�ı������Ի�õ�����ֵ
unsigned int weight[10];
unsigned int value[10];
#define  max(x,y)   (x)>(y)?(x):(y)  

int main()
{
	int N, cap;
	cin >> N;  //��Ʒ����
	cin >> cap;  //��������
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
				//1����ʱ�򱳰����������Է��µ� i ����Ʒ��ֻ��ѡ���ã�  2����ʱ�����������Է��µ� i ����Ʒ�����Ǿ�Ҫ�����������Ʒ�Ƿ��ܻ�ȡ����ļ�ֵ
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);  //ֻ����i����Ʒ�Ų���
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