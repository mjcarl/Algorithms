#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------------欧几里得算法，m与n不断相除，，n赋给m，余数赋给n。非0的最后一个余数就是最大公约数
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