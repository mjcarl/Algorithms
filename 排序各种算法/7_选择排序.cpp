#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

void exch(vector<int>&a,int i,int min)
{
	int tmp;
	tmp = a[i];
	a[i] = a[min];
	a[min] = tmp;
}
void sort(vector<int>&a)  //容器参数 （引用）   后面的数都和前面的基准数比较，遍历一遍选出子集的最值
{
	int N = a.size();
	for (int i = 0; i<N; i++)
	{
		int min = i;
		for (int j = i + 1; j<N; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
				exch(a, i, min);  //值交换
			}			
		}
	}
}

int main()
{
	vector<int>a;
	int am[100];
	int N = 0;
	cout << "enter size of numbers:" << endl;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> am[i];
		a.push_back(am[i]);
	}		
	sort(a);
	for (int i = 0; i < N; i++)
		cout << a[i] << endl;
	return 0;
}