#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool cmp(const pair<int, int>&p1, const pair<int, int>&p2)  //从小到大排序
{
	return p1.second<p2.second;
}
int main()
{
	int n, m;
	cin >> n >> m;
	map<int, int>mp;
	int i, j, x;
	for (i = 0; i<m; i++)
	{
		cin >> x;
		x--;
		mp[x]++;
	}
	auto it = mp.begin();
	/*for (; it != mp.end(); it++)
	{
		cout <<it->first<<"  "<< it->second << endl;  //打印元素没有“*”
	}*/
	vector<pair<int, int>>vec(mp.begin(), mp.end()); //为了对map的value排序，把它放到pair的数组里
	int len = vec.size();
	sort(vec.begin(), vec.end(), cmp);
	if (len < n)  //防止有的列没有元素
		cout << 0 << endl;
	else
		cout << vec[0].second << endl;

	return 0;
}
