#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, w;
vector<int> a;
int ans = 0;

void dfs(int sum_now, int loc)
{
	if (sum_now > w)
		return;
	else if (sum_now <= w)
	{
		cout << sum_now << endl;
		++ans;
	}

	for (int i = loc; i < n; i++)   //��Ϊ���ô�ӡÿ����������Բ���Ҫ��vector���д���
		dfs(sum_now + a[i], i + 1);
}


int main()
{
	cin >> n>> w;     //n����ʳ������������Ϊw
	int tmp, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
		sum += tmp;
	}
	if (sum <= w)
		ans = pow(2, n);
	else
	{
		cout << "======" << endl;
		sort(a.begin(), a.end());   //����������ģ���ΪҪ����С�İ���ʼ�жϵݹ�
		dfs(0, 0);
	}
	cout << "ans = "<< ans << endl;
	return 0;
}
