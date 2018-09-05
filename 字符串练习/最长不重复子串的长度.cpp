#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int N = str.size();
	int i, maxLen = 0;
	int pre = 0;  //在必须以str[i-1]字符结尾时，最长无重复子串开始位置的前一个位置
	int len = 0;  //以每个字符结尾的情况下，最长无重复子串长度的最大值
	map<char, int>mp;  //value为最近一次出现的地方

	for (i = 1; i <= N; i++)
	{
		if (mp[str[i-1]] == 0)   //没出现过的字符
		{
			len++;
		}
		else
		{
			int tmp = mp[str[i-1]];
			if (tmp > pre)   //是否出现在当前最长子串里，是的
			{
				pre = tmp;
				len = i - pre;
			}
			else
			{
				len++;
			}
		}
		mp[str[i-1]] = i;
		maxLen = maxLen > len ? maxLen : len;
	}
	cout << "maxLen is : " << maxLen << endl;

	return 0;
}
