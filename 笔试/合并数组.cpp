#include<iostream>
#include<set>
using namespace std;


int main()   //�ϲ��������飬ȥ�����ظ���Ԫ��
{
	int m, n;
	while (cin >> m >> n)   //ע����ô����
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