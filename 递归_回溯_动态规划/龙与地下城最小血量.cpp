#include <iostream>
#include<vector>
#include<string>
using namespace std;

int max(int a, int b);
int min(int a, int b);
int main()
{
	int M, N, i, j, maxLen = 0;
	cout << "������³ǵĴ�С�� ";
	cin >> M;
	cin >> N;
	cout << "����ÿ���ǵ�Ѫҩ�����ģ� " << endl;
	vector<vector<int>>arr(M);   
	for (i = 0; i < M; i++)
		arr[i].resize(N);
	vector<vector<int>>dp(M);   //dp[i][j]��ʾ�����ʿҪ�ߵ�(i,j)�����ҴӸ�λ��������·���������棬�������е�Ѫ��
	for (i = 0; i < M; i++)
		dp[i].resize(N);
	int tmp;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	dp[M - 1][N - 1] = max(1-arr[M-1][N-1],1);
	for (j = N - 2; j >= 0; j--)
	{
		dp[M - 1][j] = max(dp[M - 1][j + 1] - arr[M - 1][j], 1);
	}
	for (i = M - 2; i >= 0; i--)
	{
		dp[i][N - 1] = max(dp[i + 1][N - 1] - arr[i][N - 1], 1);
	}
	for (j = N - 2; j >= 0; j--)  //����
	{
		for (i = M - 2; i >= 0; i--)
		{
			dp[i][j] = max(min(dp[i][j + 1] - arr[i][j], dp[i + 1][j] - arr[i][j]), 1);
		}
	}
	cout << "���ٽ���Ѫ��Ϊ�� " << dp[0][0] << endl;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
