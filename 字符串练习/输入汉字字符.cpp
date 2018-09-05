#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	getline(cin, s);
	cin >> n;
	string t;
	int j = n;
	for (int i = 0; i < s.length() && j>1;) {
		if (s[i] <= 127 && s[i] >= 0) {
			t = t + s.substr(i, 1);
			i++;
			j--;
		}
		else {
			t = t + s.substr(i, 2);
			i = i + 2;
			j = j - 2;
		}
	}
	if (s[n - 1] <= 127 && s[n - 1] >= 0)
		t = t + s.substr(n - 1, 1);
	else {
		t = t + s.substr(n - 1, 2);
	}
	for (int i = 0; i < t.length(); i++) {
		if (t[i] >= '0'&&t[i] <= '9')
			t.erase(i, 1);
	}
	cout << t << endl;
	return 0;
}
