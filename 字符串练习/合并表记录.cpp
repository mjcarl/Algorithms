#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int>mp;
		int i, a, b;
		for (i = 0; i<n; i++)
		{
			cin >> a >> b;
			mp[a] = mp[a] + b;
		}
		auto it = mp.begin();
		for (; it != mp.end(); it++)   //Ĭ�ϰ�first��С�����ź���
		{
			cout << it->first << " " << it->second << endl;
		}
	}

	return 0;
}