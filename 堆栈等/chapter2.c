#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
//--------------------chapter 2 �㷨����--------------------

//-------------���һ�����ֵ������������֮��-----------------

static int main()     //���Ʒ�
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	int sum1,sum2,max1=0,max2=0,max3=0,max=0,i,j,k1=0,k2=0;
	for(i=0;i<4;i++)
	{
		sum1=0;
		for(j=i;j<4;j++)
		{
			sum1=sum1+a[j];
		    if(max1<sum1)
			{
			  max1=sum1;
			  k1=i;   //��һ�����һ�����ĵ�һλ�±�
			}
		}
	}
	for(i=4;i<8;i++)
	{
		sum2=0;
		for(j=i;j<8;j++)
		{
			sum2=sum2+a[j];
		    if(max2<sum2)
			{
			  max2=sum2;
			  k2=i;     //�ڶ������һ�����ĵ�һλ�±�
			}

		}
	}
	for(i=k1;i<k2;i++)
		max3=max3+a[i];
	max3=max3+max2;
	max=max1;
	if(max1<max2)
	{
		max=max2;
	    if(max2<max3)
		max=max3;
	}
	if(max1<max3)
		max=max3;
	printf("max=%d\n",max);
	return max;
}




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
		else if(sum<0)  //666
			sum=0;
	}
	printf("max=%d\n",max);
	return max;
}


//----------------�����ʽ�ĺ� (Horner�㷨)------------------------

//----��F(X)=4X^3+8X^2+X+2

#define N 4    //����
#define X 3    //X=3ʱ�Ľ��
int main()
{
	int poly=0,i,A[N];
	A[0]=4;
	A[1]=8;
	A[2]=1;
	A[3]=2;
	for(i=0;i<N;i++)
	{
		poly=poly*X+A[i];   //A[i]Ϊ����ʽ��ϵ��
	}
	printf("poly=% d\n",poly);
	return poly;
}


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


void main(void)
{
    float a=0;
    a=1.2e3;
    printf("\n%f\n",a);
}

*/