#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()   //难点：：：：若有多个，输出在较短串中最先出现的那个！
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int m = s1.size(), n = s2.size();
		string res;
		if (m == 0 || n == 0)
		{
			cout << res << endl;   return 0;
		}
		if (m > n)
		{
			swap(s1, s2);  //保证s1是短的字符串
			swap(m, n);
		}
			
		int i, j,ed = 0, max = 0;
		vector<vector<int>>dp(m);
		for (i = 0; i<m; i++)
			dp[i].resize(n,0);

		bool flag = false;
		for (i = 0; i<m; i++)  //第一列
		{
			if (s1[i] == s2[0] )
			{
				if (flag == false)
				{
					flag = true;
					ed = i;
					max = 1;
				}				
				dp[i][0] = 1;				
			}
		}
		flag = false;
		for (j = 0; j<n; j++)  //第一行
		{
			if (s1[0] == s2[j])
			{
				dp[0][j] = 1;
			}
		}

		for (i = 1; i<m; i++)
		{
			for (j = 1; j<n; j++)
			{
				if (s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j]>max)
					{
						max = dp[i][j];  ed = i;
					}
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		for (i = 0; i<max; i++)
		{
			res += s1[ed + 1 - max + i];
		}
		cout << res << endl;
	}
	return 0;
}

