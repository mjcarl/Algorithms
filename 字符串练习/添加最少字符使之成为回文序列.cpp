#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int min(int a, int b);
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int i, j;
	vector<vector<int>>dp(len);   //dp[i][j]��ʾstr[i..j]��Ҫ��ӵ���С�ַ���
	for (i = 0; i < len; i++)
		dp[i].resize(len);
	for (j = 1; j < len; j++)
	{
		dp[j - 1][j] = (str[j - 1] == str[j]) ? 0 : 1;
		for (i = j - 2; i > -1; i--)
		{
			if (str[i] == str[j])   //ͷ��β�������ַ���ͬ
			{
				dp[i][j] = dp[i + 1][j - 1];   //�൱�����ȥͷ��β�Ĵ�
			}
			else
			{
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;  //ȡ��߻��±ߵ���Сֵ����1
			}
		}
	}
	cout << "answer is : " << dp[0][len - 1] << endl;
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}