#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>vec(n);
	int dis;
	if (k >= 0)
		dis = k%n;
	else
		dis = 5 - (-k) % n;
	int i, tmp;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		vec[(i + dis) % n] = tmp;
	}
	for (auto &p : vec)
		cout << p << endl;

	return 0;
}