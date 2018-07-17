#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//----------希尔排序(缩小增量排序)--------亚二次o(N^2)
//---初始步长为gap=length/2，然后gap不断除以2，直到gap=1进行一次全组的插入排序为止----

void Shell_Sort(int a[],int N)
{
	int i,j,p;
	int temp;

	for(p=N/2;p>0;p=p/2)   //p是组数
		for(i=p;i<N;i++)
		{
			temp=a[i];
			for(j=i;j>=p;j=j-p)   //插入排序
				if(temp<a[j-p])
					a[j]=a[j-p];
				else
					break;   //因为前面都已经排过序了

			a[j]=temp;
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
	Shell_Sort(a,n-1);
	print(a,n-1);
	return 0;
}