#include <iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int>arr(N);
	map<int, int>mp;  //map±éÀú
	int i, j, tmpmax = -99999, tmpmin = 99999, maxlen = 0;

	for (i = 0; i < N; i++)
	{
		cin >> j;
		arr[i] = j;
		mp[j]++;
		tmpmax = j > tmpmax ? j : tmpmax;
		tmpmin = j < tmpmin ? j : tmpmin;
	}
	j = 0;
	for (i = tmpmin; i <= tmpmax; i++)
	{
		if (mp[i] > 0)
			j++;
		else
			j = 0;
		maxlen = maxlen > j ? maxlen : j;
	}
	cout << "maxlen = " << maxlen << endl;
	return 0;
}