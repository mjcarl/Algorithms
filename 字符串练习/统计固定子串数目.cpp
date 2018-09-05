#include<bits/stdc++.h>
using namespace std;

//int main()
//{
//	string s, res;
//	cin >> s >> res;
//	size_t pos = 0;
//	int len = 0, dis = res.size();
//	pos = s.find(res, pos);
//	while (pos != string::npos)
//	{
//		cout << pos << endl;
//		++len;
//		pos = s.find(res, pos + dis);
//	}
//	cout << len << endl;
//	return 0;
//}

int main()
{
	string s, res;
	cin >> s >> res;
	int pos, dis = res.size();
	pos = s.find(res);
	while (pos != string::npos)
	{
		s.erase(pos, dis);
		pos = s.find(res);
	}
	cout << s << endl;
	return 0;
}