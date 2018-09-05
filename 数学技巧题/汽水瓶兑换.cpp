#include<bits/stdc++.h>
using namespace std;

int mian()
{
	int n, num = 0;
	vector<int>vec;
	while (cin >> n && n != 0)
	{
		vec.push_back(n);
		num++;
	}
	int i, sum, tmp;
	for (i = 0; i<num; i++)
	{
		sum = 0;
		while (vec[i] >= 3)
		{
			tmp = vec[i] % 3;
			sum = sum + vec[i] / 3;
			vec[i] = tmp + vec[i] / 3;
		}
		if (vec[i] == 2)
			sum++;
		cout << sum << endl;
	}
	return 0;
}
