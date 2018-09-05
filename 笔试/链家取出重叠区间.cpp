#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i, a, b, num = 0;
	vector<pair<int, int>>org(n);	

	for (i = 0; i<n; i++)
	{
		cin >> a; cin >> b;
		org[i] = make_pair(a, b);
	}
	vector<pair<int, int>>vec(org.begin(), org.end());

	sort(vec.begin(), vec.end());
	auto it = vec.begin();
	auto it2 = it;  it2++;
	bool t = false;
	vector<int>p;
	for (; it2 != vec.end(); it++,it2++)
	{
		if (it->second <= it2->first)
			continue;
		if (it->second > it2->first)
		{
			auto it3 = it2;  it3++;
			if (t == true)
			{
				cout << 0 << endl;
				return 0;
			}
			if (it3 == vec.end() || (it3!=vec.end() && it2->second<=it3->first))  //两个都可以被删除
			{
				t = true;
				{
					auto pp = org.begin();
					while (pp != org.end())
					{
						if (pp->first == it->first && pp->second == it->second)
						{
							p.push_back(pp - org.begin() + 1);
						}
						if (pp->first == it2->first && pp->second == it2->second)
						{
							p.push_back(pp - org.begin() + 1);
						}
						pp++;
					}
				}
				it++; it2++;
				if (it2 == vec.end())
					break;
			}
			if (it3 != vec.end() && it2->second > it3->first)   //只能删除第二个
			{
				if (it->second > it3->first)
				{
					cout << 0 << endl;
					return 0;
				}
				t = true;
				{
					auto pp = org.begin();
					while (pp != org.end())
					{
						if (pp->first == it2->first && pp->second == it2->second)
						{
							p.push_back(pp - org.begin() + 1);
							break;
						}
						pp++;
					}
				}
				it++; it2++;
				if (it2 == vec.end())
					break;
			}
		}		
	}
	if (t == true)
	{
		int len = p.size();
		cout << len << endl;
		sort(p.begin(), p.end());
		for (i = 0; i < len-1; i++)
		{
			cout << p[i] << " ";
		}
		cout << p[i] << endl;
	}
	else
	{
		cout << n << endl;
		for (i = 0; i < n-1; i++)
			cout << i+1 << " ";
		cout << i+1 << endl;
	}
	return 0;
}


