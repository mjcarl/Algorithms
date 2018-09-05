#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, k, d;
	//一定要初始化，如果放到main的外面，会自动初始化为0，但是再main的里面，初始化的数未知！
	long long maxval[55][15] = { 0 }, minval[55][15] = { 0 }; 
	cin >> n;
	int a[55];
	int i, j, h;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k >> d;
	if (n == 1)
	{
		cout << a[0];
		return 0;
	}
	long long res = 0;

	//max[i][j]是i+1个人里面选j+1个学生，且最后一个学生是第j+1
	for (i = 0; i < n; i++)  //初始化第一列
	{
		maxval[i][0] = a[i];
		minval[i][0] = a[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < k; j++)
		{
			for (h = i - 1; h >= max(0, i - d); h--)
			{
				maxval[i][j] = max(maxval[i][j], max(maxval[h][j - 1] * a[i], minval[h][j - 1] * a[i]));

				minval[i][j] = min(minval[i][j], min(maxval[h][j - 1] * a[i], minval[h][j - 1] * a[i]));
			}
		}
		res = max(res, max(maxval[i][k - 1], minval[i][k - 1]));
	}
	cout << res << endl;

	return 0;
}