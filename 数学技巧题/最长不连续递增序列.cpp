#include<bits/stdc++.h>
using namespace std;

struct qiann
{
	int val;
	int lian;
};
int main()
{
	long n, t;
	while (cin >> n >> t)
	{
		vector<long>vec(n, 0);
		vector<pair<int, int>>res;
		int i, j, maxlen = 0, maxval = 0;
		for (i = 0; i<n; i++)
			cin >> vec[i];
		struct qiann qian;
		qian.val = 0;   qian.lian = 0;
		for (i = 0; i<t; i++)
		{
			for (j = 0; j<n; j++)
			{
				if (qian.val<vec[j])
				{
					if (vec[j] >= maxval)
					{
						maxval = vec[j];
						maxlen = maxlen + 1;
						qian.lian = maxlen;
						res.push_back({ vec[j],maxlen });
					}
					else
					{
						qian.lian++;
						res.push_back({ vec[j],qian.lian });
					}
					qian.val = vec[j];
				}
				else
				{
					auto it = (res.end()--);
					while (it>res.begin())
					{
						if (it->first<vec[j])
						{
							qian.lian = it->second + 1;
							res.push_back({ vec[j],qian.lian });
						}
						it--;
					}
					if (it == res.begin())
					{
						if (it->first<vec[j])
						{
							qian.lian = it->second + 1;
							res.push_back({ vec[j],qian.lian });
						}
						else
						{
							qian.lian = 1;
							res.push_back({ vec[j],qian.lian });
						}
					}
					qian.val = vec[j];
				}
			}
		}
		cout << maxlen << endl;
	}
	return 0;
}