#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//--------插入排序（由N-1趟排序数组组成）------
//--------时间复杂度为O(N^2)---交换相邻元素的都是平均需要（N^2）  类似于挖坑的整理牌的顺序
void InsertionSort(int a[],int N)
{
	int temp;
	int i,p;
	for(p=1;p<N;p++)
	{
		temp=a[p];
		for(i=p;i>0 && a[i-1]>temp;i--)  //核心
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
	printf("请输入数组，输入-1停止：\n");
	scanf("%d",&a[n++]);
	while(a[n-1]!=-1)
		scanf("%d",&a[n++]);
	InsertionSort(a,n-1);
	print(a,n-1);
	return 0;
}

