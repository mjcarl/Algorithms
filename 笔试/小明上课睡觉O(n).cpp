#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>vec(n);
	vector<int>wake(n);
	int i, j,  max = 0, tmp = 0;
	for (i = 0; i<n; i++)
	{
		cin >> vec[i];
	}
	for (i = 0; i<n; i++)
	{
		cin >> wake[i];  //1��ʾ���ѣ�ֻ����0��ʱ�������
	}
	int it1 = 0, it2;
	while (wake[it1] != 0)  //�ҵ�һ���ܽ��ѵ�λ��
	{
		it1++;
	}
	if ((n - it1) >= k)
	{
		it2 = it1 + k;
		for (j = 0; j<n; j++)
		{
			if (wake[j] == 1 && (j<it1 || j >= it2))
			{
				tmp = tmp + vec[j];
			}
			if (j >= it1 && j<it2)
			{
				tmp = tmp + vec[j];
			}
		} 
		max = tmp;  //��һ������Ҫ��Ĵ�С
		while(it2 < n)  //���������ƶ�
		{
			if (wake[it1] == 0)
				tmp = tmp - vec[it1];
			if (wake[it2] == 0)
				tmp = tmp + vec[it2];
			if (tmp>max)
				max = tmp;
			it1++;
			it2++;
		}
	}
	else
	{
		for (j = 0; i < n; j++)
		{
			if (wake[j] == 1 && (j < it1))
				max = max + vec[j];
			else
				max = max + vec[j];
		}
	}
	cout << max << endl;
	return 0;
}


