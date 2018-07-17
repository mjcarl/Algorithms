#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�����ν������������������п���  1.���������� 2. �����Ϊ��������ѭ�� 3. �ݹ����ж��������ڽ���forѭ���ݹ���������Ÿ���ȼ�1

#define SCORE 100
int N;
vector<int> a;
bool x[100];   //��ʾ�������ǰ�Ƿ���sum��
int sum = 0;
int num = 0;
void backtrace(int deep)  //deep��ʾ���
{
	if(sum > SCORE)
		return;
	if (sum == SCORE)
	{
		cout << "������" << num << endl;
		for (int i = 0; i < N; i++)
		{
			if (x[i] == true)
				cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	if (deep == N)
		return;
	for (int j = deep; j < N; j++)
	{
		if (x[j] == false)
		{
			x[j] = true;
			sum += a[j];
			num++;
			backtrace(j + 1);   //ע����j+1
			x[j] = false;
			sum -= a[j];
			num--;
			while (j < N - 1 && a[j] == a[j + 1])   //�����ظ�Ԫ��   ��������20 40 40 40...  ������20 40 40
				++j;
		}		
	}
}


int main()
{	
	cin >> N;
	int tmp;	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());  //����  ��ֹ�ظ�Ԫ�ظ���	
	backtrace(0);

	return 0;
}