#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

size_t getCommLen(string str1, string str2) {
	size_t i;
	for (i = 0; i < str1.size() && i < str2.size(); i++) {
		if (str1[i] != str2[i])
			break;
	}
	return i;
}
int main()
{
	string str;
	cin >> str;
	vector<string> strs;
	for (size_t i = 0; i < str.size(); i++) {
		strs.push_back(str.substr(i));   //Ä¬ÈÏÎªµ¹ÐòÊä³ö
		//cout << str.substr(i) << endl;
	}
	sort(strs.begin(), strs.end());

	size_t maxLen = 0;
	for (size_t i = 0; i < strs.size() - 1; i++) {
		size_t len = getCommLen(strs[i], strs[i + 1]);
		maxLen = max(maxLen, len);
	}
	cout << maxLen * 2 << endl;

	system("pause");
	return 0;
}