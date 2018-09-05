#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	char c;
	cin >> s;  cin >> c;
	map<char,int>mp;
	int i = 0;
	while (i < s.size())
	{
		mp[s[i]]++;
		i++;
	}
	if (c >= 'a'&&c <= 'z')
	{
		char other = c - ('a' - 'A');
		cout << mp[c] + mp[other] << endl;
	}
	else if (c >= 'A'&&c <= 'Z')
	{
		char other = c + ('a' - 'A');
		cout << mp[c] + mp[other] << endl;
	}
	else
		cout << mp[c] << endl;
	return 0;
}