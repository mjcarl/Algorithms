#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------------ŷ������㷨��m��n�����������n����m����������n����0�����һ�������������Լ��
int Gcd(int m,int n)
{
	int re=0;
	int temp;
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	while(n>0)
	{
		re=m%n;
		m=n;
		n=re;
	}
	return m;
}

void main()
{
	int y=0;
	int m,n;
	scanf("%d %d",&m,&n);
	y=Gcd(m,n);
	printf("answer is %d\n",y);
}