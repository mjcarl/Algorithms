#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------------��һ��������ҪԪ��(���������ܸ�����һ��)----------------------
//���������Աȵķ������Ƚ�A1��A2�Ƿ���ͬ����ͬ�����b�����У�Ȼ��Ƚ�A3��A4.... ���B�����Ԫ����Ϊ��ѡԪ�����бȽϡ�
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
	b[k]=a[2*(i+1)];  //ȡ��ѡԪ�ŵ�b[]��

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
