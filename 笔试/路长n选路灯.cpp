#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	int t, n;
	int num = 0;
	int ans[1000];
	string s0;
	vector<char> s;
	cin >> t;   //t个例子
	for (int k = 0; k < t; k++)
	{
		num = 0;
		s.clear();

		cin >> n;  //n的路长
		cin >> s0;
		for (int j = 0; j < s0.length(); j++)
			s.push_back(s0[j]);
		s.insert(s.begin(), 'X');
		s.insert(s.end(), 'X');
		vector<char>::iterator str = (++s.begin());  //中
		vector<char>::iterator str1;  //前
		vector<char>::iterator str2;  //后
		vector<char>::iterator stend = (--s.end());

		for (; str < stend; str++)
		{
			str1 = str;
			str2 = str;
			str1--;
			str2++;
			if (*str1 == '.')
			{
				if (*str2 == '.')
				{
					num++;
					*str = 'X';
					*str1 = 'X';
					*str2 = 'X';
				}
				else if (*str2 == 'X')
				{
					num++;
					*str1 = 'X';
					*str = 'X';
				}
			}
			if (str == (s.end()-2))
			{
				if (*str1 == 'X' && *str == '.')
					num++;
			}
		}
		ans[k] = num;
	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << endl;

	return 0;
}





