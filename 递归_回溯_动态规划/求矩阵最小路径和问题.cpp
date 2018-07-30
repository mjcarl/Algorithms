#include<iostream>
#include<algorithm>

using namespace std;

const int M = 3;
const int N = 3;

int dis(int arr[][N], int dp[][N]);
int min(int a, int b);

int main()
{
	int i, j, tmp, minDis;
	int arr[M][N] = { 0 }, dp[M][N] = { 0 };   //�����С·���͵ľ���

	for(i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			cin >> tmp;
			arr[i][j] = tmp;
		}
	
	dp[0][0] = arr[0][0];
	for (i = 1; i < M; i++)    //��ʼ����һ�е�һ��
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	for (i = 1; i < N; i++)
		dp[0][i] = dp[0][i - 1] + arr[0][i];

	minDis = dis(arr,dp);
	cout << "��С·���ĺ�Ϊ�� " << minDis << endl;
	return 0;
}

int dis(int arr[][N], int dp[][N])
{
	int i, j, d;
	for (i = 1; i < M; i++)
	{
		for (j = 1; j < N; j++)
		{
			dp[i][j] = min( dp[i - 1][j] , dp[i][j - 1] ) + arr[i][j];
		}
	}
	return dp[M-1][N-1];
}

int min(int a, int b)
{
	return a < b ? a : b;
}