#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	auto it = s.begin();
	int fu = 0, tmp=0;
	int shu = 0, sum = 0;
	for (; it != s.end(); it++)
	{
		if (*it >= '0' && *it <= '9')
		{
			tmp = tmp * 10 + (*it - '0');
			if (fu > 0 && fu % 2 == 1)
			{
				shu = 1;  //负数
			}
			else
				shu = 2;  //正数
		}
		else if (*it == '-')
		{
			if (shu == 1)
			{
				sum -= tmp;
				shu = 0;
				tmp = 0;
				fu = 0;
			}
			if (shu == 2)
			{
				sum += tmp;
				shu = 0;
				tmp = 0;
				fu = 0;
			}
			fu++;
		}
		else
		{
			if (shu == 1)
			{
				sum -= tmp;
			}
			if (shu == 2)
			{
				sum += tmp;
			}
			shu = 0;
			tmp = 0;
			fu = 0;
		}
	}
	if (shu == 1)
	{
		sum -= tmp;
	}
	if (shu == 2)
	{
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}