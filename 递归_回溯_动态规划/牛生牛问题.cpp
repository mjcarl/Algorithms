#include<bits/stdc++.h>
using namespace std;


int f1(int yue)   //----O(2^N)
{
	if (yue < 1)
		return 0;
	if (yue == 1 || yue == 2 || yue == 3)
		return yue;
	return f1(yue - 1) + f1(yue - 3);

}

int f(int n)  //----O(N)
{
	if (n < 1)
		return 0;
	if (n == 1 || n == 2 || n == 3)
		return n;
	int res = 3;
	int pre = 2;
	int prepre = 1;
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 4; i <= n; i++)
	{
		tmp1 = res;
		tmp2 = pre;
		res = res + prepre;
		pre = tmp1;
		prepre = tmp2;
	}
	return res;
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		int num, yue, res;
		cin >> num >> yue;
		res = f(yue)+1;
		res = res*num;
		cout << res << endl;
	}
	return 0;
}