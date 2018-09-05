#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();
		int pos, max = 0;
		vector<int>dp(len, 0);  //
		for (int i = 1; i < len; i++)   //O(N)
		{
			if (s[i] == ')')
			{
				pos = i - dp[i - 1] - 1;   // )对应的(位置
				if (s[pos] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					int qian=0;
					if (pos - 1 >= 0)
						qian = dp[pos - 1]; // 如果(之前还是可用的，就要加上前面的
					dp[i] += qian;
				}
			}
			if (max<dp[i])
				max = dp[i];
		}
		cout << max << endl;
	}
	return 0;
}
