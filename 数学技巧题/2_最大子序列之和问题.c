#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//-------------���һ�����ֵ������������֮��-----------------
int main()      //�����㷨--best    һ��ɨ����������
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	int sum,max,j;
	sum=max=0;
	for(j=0;j<8;j++)
	{
		sum=sum+a[j];
		if(sum>max)
			max=sum;
		else if(sum<0)
			sum=0;
	}
	printf("max=%d\n",max);
	return max;
}
