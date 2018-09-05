#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a[5] = { 0,2,4,6,8 };
	vector<int>vec(a, a + 4);
	int x, y, m = 4;
	x = *lower_bound(a, a + 4, m);  //���ص�һ�����ڵ���m��ֵ�����û�оͷ������һ��
	y = lower_bound(a, a + 4, m) - a;    //���ص�һ�����ڵ���m���±�    
	auto it = upper_bound(vec.begin(), vec.end(), m);  //upper_bound(first, last, val)�㷨����һ���ǵݼ�����[first, last)�е�һ������val��λ�õĵ�������
	int dis = upper_bound(vec.begin(), vec.end(), m) - vec.begin();
	cout << "lower_bound" << endl;
	cout << x << "  ���±�= " << y << endl;
	cout << "upper_bound" << endl;
	if(it!=vec.end())
		cout << *it<< "  ���±�= "<<dis<<endl;
	return 0;
}