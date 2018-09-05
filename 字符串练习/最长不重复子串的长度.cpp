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
	int pre = 0;  //�ڱ�����str[i-1]�ַ���βʱ������ظ��Ӵ���ʼλ�õ�ǰһ��λ��
	int len = 0;  //��ÿ���ַ���β������£�����ظ��Ӵ����ȵ����ֵ
	map<char, int>mp;  //valueΪ���һ�γ��ֵĵط�

	for (i = 1; i <= N; i++)
	{
		if (mp[str[i-1]] == 0)   //û���ֹ����ַ�
		{
			len++;
		}
		else
		{
			int tmp = mp[str[i-1]];
			if (tmp > pre)   //�Ƿ�����ڵ�ǰ��Ӵ���ǵ�
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
