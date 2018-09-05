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
	x = *lower_bound(a, a + 4, m);  //返回第一个大于等于m的值，如果没有就返回最后一个
	y = lower_bound(a, a + 4, m) - a;    //返回第一个大于等于m的下标    
	auto it = upper_bound(vec.begin(), vec.end(), m);  //upper_bound(first, last, val)算法返回一个非递减序列[first, last)中第一个大于val的位置的迭代器。
	int dis = upper_bound(vec.begin(), vec.end(), m) - vec.begin();
	cout << "lower_bound" << endl;
	cout << x << "  其下标= " << y << endl;
	cout << "upper_bound" << endl;
	if(it!=vec.end())
		cout << *it<< "  其下标= "<<dis<<endl;
	return 0;
}