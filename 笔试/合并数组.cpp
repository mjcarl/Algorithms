#include<iostream>
#include<set>
using namespace std;


int main()   //合并两个数组，去除掉重复的元素
{
	int m, n;
	while (cin >> m >> n)   //注意这么输入
	{
		set<int> s;
		int t;
		for (int i = 0; i<m; ++i)
		{
			cin >> t;
			s.insert(t);
		}
		for (int i = 0; i<n; ++i)
		{
			cin >> t;
			s.insert(t);
		}
		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	return 0;
}