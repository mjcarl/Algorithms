#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>>geshu(n);
	for (int i = 0; i<n; i++)
		geshu[i].resize(2);
	vector<vector<int>>res(n);
	for (int i = 0; i<n; i++)
		res[i].resize(2);
	int i, j;
	for (i = 0; i<n; i++)
	{
		cin >> geshu[i][0];
		geshu[i][1] = i;
	}
	int p = 0, im;
	for (im = 0; im<k; im++)
	{
		{
			for (i = 0; i<n; i++)  //选择排序  从小到大
			{
				int min = i;
				for (j = i + 1; j<n; j++)
				{
					if (geshu[j][0] < geshu[min][0])
					{
						int a, b;
						a = geshu[j][0];
						b = geshu[j][1];
						geshu[j][0] = geshu[min][0];
						geshu[j][1] = geshu[min][1];
						geshu[min][0] = a;
						geshu[min][1] = b;
					}
				}
			}
		}
		//cout << geshu[n - 1][1] << "--- " << geshu[0][1] << endl;
		if (geshu[n - 1][0] - geshu[0][0] <= 1)
			break;
		else
		{
			geshu[n - 1][0]--;
			geshu[0][0]++;
			
			res[p][0] = geshu[n - 1][1] + 1;
			res[p][1] = geshu[0][1] + 1;
			p++;
		}
	}
	if (im == k)
	{
		for (i = 0; i<n; i++)  //选择排序  从小到大
		{
			int min = i;
			for (j = i + 1; j<n; j++)
			{
				if (geshu[j][0] < geshu[min][0])
				{
					int a, b;
					a = geshu[j][0];
					b = geshu[j][1];
					geshu[j][0] = geshu[min][0];
					geshu[j][1] = geshu[min][1];
					geshu[min][0] = a;
					geshu[min][1] = b;
				}
			}
		}
	}
	cout << geshu[n - 1][0] - geshu[0][0] << " " << im<< endl;
	for (i = 0; i<p; i++)
		cout << res[i][0] << " " << res[i][1] << endl;
	return 0;
}