#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------����������N-1������������ɣ�------
//--------ʱ�临�Ӷ�ΪO(N^2)---��������Ԫ�صĶ���ƽ����Ҫ��N^2��  �������ڿӵ������Ƶ�˳��
void InsertionSort(int a[],int N)
{
	int temp;
	int i,p;
	for(p=1;p<N;p++)
	{
		temp=a[p];
		for(i=p;i>0 && a[i-1]>temp;i--)  //����
			a[i]=a[i-1];
		a[i]=temp;
	}
}
void print(int a[],int N)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(void)
{
	int n=0;
	int a[100];
	printf("���������飬����-1ֹͣ��\n");
	scanf("%d",&a[n++]);
	while(a[n-1]!=-1)
		scanf("%d",&a[n++]);
	InsertionSort(a,n-1);
	print(a,n-1);
	return 0;
}

