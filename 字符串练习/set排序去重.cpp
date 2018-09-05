#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	set<int>st;
	while (cin >> n)  //最好写成循环输入
	{
		int i, tmp;
		st.clear();
		for (i = 0; i<n; i++)
		{
			cin >> tmp;
			st.insert(tmp);
		}
		for (auto &p : st)
			cout << p << endl;
	}

	return 0;
}