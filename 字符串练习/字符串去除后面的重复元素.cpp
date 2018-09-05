#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int>mp;
	auto it = s.begin();
	string res;
	for (; it != s.end(); it++)
	{
		if (mp[*it] == 0)
		{
			mp[*it]++;
			res = res + *it;
		}			
	}
	cout << res << endl;
	return 0;
}
