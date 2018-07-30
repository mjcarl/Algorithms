#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int i, k, start = -1, len = 0;
	cin >> k;
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			start = (start == -1) ? i : start;
			len++;
		}
		else
		{
			if (len == k)
			{
				while (len > 0)
				{
					s[start] = 0;
					start++; len--;
				}
			}
			start = -1;
			len = 0;
		}
	}
	if (len == k)
	{
		while (len > 0)
		{
			s[start] = 0;
			start++; len--;
		}
	}
	s.erase(remove(s.begin(), s.end(), 0), s.end());  //删除string中的指定元素
	cout << "output string : " << s << endl;
	return 0;
}