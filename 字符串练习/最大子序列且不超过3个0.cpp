#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int i = 0, j = 0, a, sumtemp = 0, maxsum = 0, numofzero = 0;
	int n;
	cin >> n;
	vector<int> vec;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	for (j = 0; j < n; j++)
	{
		sumtemp = sumtemp + vec[j];
		if (vec[j] == 0)
			++numofzero;
		if (numofzero > 3)
			sumtemp = 0;
		if (sumtemp > maxsum)
		{
			maxsum = sumtemp;
		}
			
		else if (sumtemp <= 0)
		{
			sumtemp = 0;
			numofzero = 0;
		}
			
	}
	if(maxsum>0)
		cout<<maxsum<<endl;
	else  //全是负元素
	{
		maxsum = vec[0];
		for (i = 1; i < n; i++)
		{
			if (maxsum < vec[i])
				maxsum = vec[i];
		}
		cout << maxsum << endl;
	}

	return 0;
}