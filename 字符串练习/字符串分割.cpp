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
	p = strtok(c, delim);   //strtok�ָ�char*����
	while (p)
	{
		cout << p << endl;
		p = strtok(NULL, delim);
	}
	cout << "========string sתchar*�ָ�" << endl;
	vector<string>res;  //����ָ���ÿ���ַ���
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
	cout << "========string s��find�ָ�" << endl;
	res.clear();
	cin >> s;
	s += delim;  //����βҲ���Ϸָ��������ڲ���
	int start = 0;
	int last = s.find(delim);
	while (last < s.size())
	{
		if (start != last)
		{
			res.push_back(s.substr(start, last - start));  //��start��ʼ��(last-start)����
			cout << *(res.end() - 1) << endl;
			start = last + 1; //�ָ����ĺ���һ��λ��
			last = s.find(delim, start);  //��start��ʼ����
		}
	}

	return 0;
}