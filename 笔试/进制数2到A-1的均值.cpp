#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//ʮ������123���Ϊ16����ʱֻ������λ��7��11��B�����ð˽��Ʊ�ʾʱΪ��λ��1��7��3������ͬ���Ʊ��ʱ������λ���ĺ�Ҳ��ͬ��
//������������ʮ�����ƺͰ˽����и�λ���ĺͷֱ���18��11��
//СB����Ȥ���ǣ�һ����A�����2��A - 1���Ʊ��ʱ������λ��֮�͵ľ�ֵ�Ƕ��٣�
int maxdivisor(int a, int b);
int main()
{
	int m; 
	int sum = 0, tmp;
	while (cin >> m)
	{
		int s = m;
		for (int i = 2; i < s; i++)
		{
			m = s;
			tmp = m % i;			
			while (m > 0)
			{
				sum += tmp;
				m = m / i;
				tmp = m % i;
			}
		}
		int d = maxdivisor(sum,s-2);
		cout << sum/d << "/" << (s - 2)/d << endl;   //����ֱ�������Ҫ�������������Լ����Ȼ�󻯼�
		sum = 0;
	}
	return 0;
}
int maxdivisor(int a, int b)   //****�����Լ��  a>b
{
	int d;
	while ((a % b) != 0)
	{
		d = a%b;
		a = b;
		b = d;
	}
	
	return b; 
}
