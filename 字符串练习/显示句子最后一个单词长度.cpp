#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string input;
	vector<string>arr;
	while (cin >> input) {
		arr.push_back(input);
	}
	cout << arr[arr.size() - 1].length() << endl;   //按ctrl+z 回车停止输入
	return 0;
}