#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	cout << "==========char c[100]" << endl;
	char c[100];
	cin >> c;
	char *p;
	const char *delim = ",";
	p = strtok(c, delim);   //strtok分割char*类型
	while (p)
	{
		cout << p << endl;
		p = strtok(NULL, delim);
	}
	cout << "========string s转char*分割" << endl;
	vector<string>res;  //保存分割后的每个字符串
	string s;
	cin >> s;
	char *str = new char[s.length() + 1];
	strcpy(str, s.c_str());
	p = strtok(str, delim);
	while (p)
	{
		string ss = p;
		cout << ss << endl;
		res.push_back(ss);
		p = strtok(NULL, delim);
	}
	cout << "========string s用find分割" << endl;
	res.clear();
	cin >> s;
	s += delim;  //给结尾也加上分隔符，便于操作
	int start = 0;
	int last = s.find(delim);
	while (last < s.size())
	{
		if (start != last)
		{
			res.push_back(s.substr(start, last - start));  //从start开始的(last-start)个数
			cout << *(res.end() - 1) << endl;
			start = last + 1; //分隔符的后面一个位置
			last = s.find(delim, start);  //从start开始查找
		}
	}

	return 0;
}