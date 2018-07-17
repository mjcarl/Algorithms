#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	char s1[100];
	cin >> s1;
	string s(s1);

	int max = 0, num = 0, i;
	auto it1 = s.begin();
	auto it2 = s.begin() + 1;
	auto it3 = s.begin();
	auto it4 = s.begin();
	auto it5 = s.begin();
	auto it6 = s.begin();

	for(;it1!=s.end()-1;it1++)
		for (it2 = it1 + 1; it2 != s.end(); it2++)
		{
			if (*it1 == *it2)
			{
				num = 1;
				it4 = it1;
				it3 = it5 = it2;
				it4++; it5++;
				while (it5 != s.end() && it4 != it3 && *it4 == *it5)
				{
					num++;
					it4++;
					it5++;
				}
				if (num > max)
				{
					max = num;
					it6 = it3;
				}					
			}
		}
	cout << max <<"  "<<*it6<< endl;
	string ss(it6,it6+max);
	char *sss = (char *)ss.c_str();   //必须有string到char*的转换
	cout << sss << endl;
	return 1;
}