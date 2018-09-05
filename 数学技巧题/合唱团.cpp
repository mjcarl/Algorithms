#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, k, d;
	//һ��Ҫ��ʼ��������ŵ�main�����棬���Զ���ʼ��Ϊ0��������main�����棬��ʼ������δ֪��
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

	//max[i][j]��i+1��������ѡj+1��ѧ���������һ��ѧ���ǵ�j+1
	for (i = 0; i < n; i++)  //��ʼ����һ��
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