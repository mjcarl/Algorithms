#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();  int i, j, max = 0, pos;  bool flag = false;
		if (len <= 1)
		{
			cout << " " << 0 << endl;
		}
		vector<vector<int>>vec(len);
		for (i = 0; i<len; i++)
			vec[i].resize(len, 0);
		for (j = 1; j<len; j++)
		{
			if (s[0] == s[j])
			{
				vec[0][j] = 1;
				if (flag == false)
				{
					flag = true;
					max = 1;   pos = j;
				}
			}

		}
		for (i = 1; i<len; i++)
		{
			for (j = i + 1; j<len; j++)
			{
				if (s[i] == s[j])
				{
					vec[i][j] = vec[i - 1][j - 1] + 1;
					if (vec[i][j]>max)
					{
						max = vec[i][j];  pos = j;
					}
				}
				else
					vec[i][j] = 0;
			}
		}
		string r;
		for (i = 0; i<max; i++)
		{
			r += s[pos + 1 - max + i];
		}
		cout << r << " " << max << endl;
	}
	return 0;
}