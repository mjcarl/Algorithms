#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------------求一组数的主要元素(个数超过总个数的一半)----------------------
//采用两两对比的方法，比较A1和A2是否相同，相同则放在b数组中，然后比较A3和A4.... 最后将B数组的元素作为候选元，进行比较。
#define N 9
void main()
{
	int a[N],b[N],i,k=0,j,num[(N+1)/2],max=0,p=-1;
	a[0]=3; a[1]=3; a[2]=4; a[3]=4; a[4]=3; a[5]=3; a[6]=4; a[7]=4; a[8]=4;
	num[0]=0; num[1]=0; num[2]=0; num[3]=0; num[4]=0;
	for(i=0;i<4;i++)
	{
		if(a[2*i]==a[2*i+1])
			b[k++]=a[2*i];
	}
	b[k]=a[2*(i+1)];  //取候选元放到b[]中

	for(i=0;i<=k;i++)
	{
		for(j=0;j<N;j++)
		{
			if(b[i]==a[j])
				num[i]++;
		}
	}

	for(j=0;j<=i;j++)
	{
		if(max<num[j])
		{
			max=num[j];
			p=j;
		}
	}
	if(p!=-1)
	   printf("max=% d\n",b[p]);
	else
	   printf("error!!\n");
}
