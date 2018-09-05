#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//-------------输出一行数字的最大连续序列之和-----------------
int main()      //联机算法--best    一次扫描读过出结果
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
