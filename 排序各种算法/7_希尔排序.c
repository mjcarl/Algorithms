#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//----------ϣ������(��С��������)--------�Ƕ���o(N^2)
//---��ʼ����Ϊgap=length/2��Ȼ��gap���ϳ���2��ֱ��gap=1����һ��ȫ��Ĳ�������Ϊֹ----

void Shell_Sort(int a[],int N)
{
	int i,j,p;
	int temp;

	for(p=N/2;p>0;p=p/2)   //p������
		for(i=p;i<N;i++)
		{
			temp=a[i];
			for(j=i;j>=p;j=j-p)   //��������
				if(temp<a[j-p])
					a[j]=a[j-p];
				else
					break;   //��Ϊǰ�涼�Ѿ��Ź�����

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
	printf("���������飬����-1ֹͣ��\n");
	scanf("%d",&a[n++]);
	while(a[n-1]!=-1)
		scanf("%d",&a[n++]);
	Shell_Sort(a,n-1);
	print(a,n-1);
	return 0;
}