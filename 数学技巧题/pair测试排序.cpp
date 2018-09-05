#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp_f(pair<int, int>a, pair<int, int>b)
{
	return a.first<b.first;  //����fisrt��ֵ��������
					
}
bool cmp_e(pair<int, int>a, pair<int, int>b)
{
	return a.second<b.second;
						  
}
void print(vector<pair<int, int>>&vec)
{
	cout << "=================" << endl;
	auto it = vec.begin();
	for (; it != vec.end(); it++)
	{
		cout << "[" << it->first << "," << it->second << "]" << endl;
	}
}
int main()
{
	vector<pair<int, int>>vec_first;
	vector<pair<int, int>>vec_sec;
	vector<pair<int, int>>vec_all;
	int a, b;
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		vec_first.push_back({ a, b });
		vec_sec.push_back({ a, b });
		vec_all.push_back({ a, b });
	}
	sort(vec_first.begin(), vec_first.end(), cmp_f);  //����first����
	sort(vec_sec.begin(), vec_sec.end(), cmp_e);   //����second����
	sort(vec_all.begin(), vec_all.end());   //����first������second
	print(vec_first);
	print(vec_sec);
	print(vec_all);
	return 0;
}