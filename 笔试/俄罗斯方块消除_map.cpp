#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool cmp(const pair<int, int>&p1, const pair<int, int>&p2)  //��С��������
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
		cout <<it->first<<"  "<< it->second << endl;  //��ӡԪ��û�С�*��
	}*/
	vector<pair<int, int>>vec(mp.begin(), mp.end()); //Ϊ�˶�map��value���򣬰����ŵ�pair��������
	int len = vec.size();
	sort(vec.begin(), vec.end(), cmp);
	if (len < n)  //��ֹ�е���û��Ԫ��
		cout << 0 << endl;
	else
		cout << vec[0].second << endl;

	return 0;
}
