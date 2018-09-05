#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1)
	{
		cin >> s2;
		int len1 = s1.size();
		int len2 = s2.size();
		while (s1.size() >= 8)
		{
			cout << s1.substr(0, 8) << endl;
			s1 = s1.substr(8);
		}
		if (s1.size()>0)
		{
			while (s1.size() != 8)
				s1 += '0';
		}
		cout << s1 << endl;
		while (s2.size() >= 8)
		{
			cout << s2.substr(0, 8) << endl;
			s2 = s2.substr(8);
		}
		if (s2.size()>0)
		{
			while (s2.size() != 8)
				s2 += '0';
		}
		cout << s2;
	}
	return 0;
}

/*

#include <iostream>
#include <string>
using namespace std;

void fuck(string str) {
	if (str == "")
		return;
	if (str.size() <= 8) {
		str.append(8 - str.size(), '0');
		cout << str << endl;
		return;
	}
	cout << str.substr(0, 8) << endl;
	fuck(str.substr(8, str.size()));
}
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	fuck(str1);
	fuck(str2);
	return 0;
}

*/