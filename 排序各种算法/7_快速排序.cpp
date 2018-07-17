#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//------��������O(N logN)��---------
//------��ŦԪ-----------      //ע��߽��ѡȡ������  ע���ظ�Ԫ�ض಻��

static int p=0;
void print(int a[],int N)
{
	int i;
	for(i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
inline void swap(int &a,int &b) //����������  ����
{
	int t;
	t=a;
	a=b;
	b=t;
}

int median3(int a[],int low,int high)   //ʵ����������ֵ�ָ/��ȡ���з�
{
	int center=(low+high)/2;
	if(a[low]>a[center])
		swap(a[low],a[center]);
	if(a[low]>a[high])
		swap(a[low],a[high]);
	if(a[center]>a[high])
		swap(a[center],a[high]);
	swap(a[center],a[high-1]);   //��Ϊa[high]һ����С��a[center]������ʱֻ����a[high-1]ǰ��Ԫ��
	return a[high-1];      //������Ҫ�ƶ�����ȷλ�õ���ŦԪֵ
}
inline void compare(int a[],int low,int high)
{
	if(a[low]>a[high])
		swap(a[low],a[high]);
}
static void QuickSort(int a[],int low,int high)   //������,�ظ�Ԫ�ؽ���ʱ
{
	int i,j;
	int pivot;
	
	i=low;  //��ʾ��ǵ�
	j=high-1;
	if(i<j) //ʣ��Ԫ������Ϊ3��
	{
		pivot=median3(a,low,high);  //��ȡ���з֣�ȡ��λ����Ч�����  ************************  ����������ʱ��������
	
		while(1)
		{
			while(a[++i]<pivot)
			{ }
			while(a[--j]>pivot)
			{ }
			if(i<j)  //i����j��ǰ��
				swap(a[i],a[j]);
			else
				break;
		}
		swap(a[i],a[high-1]);   //restore pivot
		QuickSort(a,low,i-1);   //ע��߽�
		QuickSort(a,i+1,high);
	}
	else if(i==j)  //ֻʣ����Ԫ�ص�����
		compare(a,i,j+1);
}

static void Quick3way(int a[],int low,int high)  //���н϶��ظ�Ԫ��ʱ�������зֵĿ�������
{
	if(low>=high)
		return;
	int lt=low,i=low+1,gt=high;
	int pivot = a[low];  //pivotѡ�������
	while(i<=gt)
	{
		if(a[i]<pivot)
		{
			swap(a[lt],a[i]);
			lt++; i++;
		}
		else if(a[i]>pivot)
		{
			swap(a[i],a[gt]);
			gt--;
		}
		else
			i++;
	}  
	//���� a[low..lt-1]<pivot=a[lt..gt]<a[gt+1,,high]
	Quick3way(a,low,lt-1);
	Quick3way(a,gt+1,high);
}
int main(void)
{
	static int n=0;
	int a[100];
	cout<<"��������---���������飬����-1ֹͣ"<<endl;
	cin>>a[0];
	while(a[n]!=-1)
		cin>>a[++n];
	//int x[10]={5,8,2,1,7,9,0,18,4,23};
	//random_shuffle(x,x+10);  //��������
	cout<<"========================="<<endl;
	print(a,n);
	QuickSort(a,0,n-1);  //n����Ч����
	//Quick3way(a,0,n-1);
	cout<<"���������"<<endl;
	print(a,n);

	return 0;
}



//void InsertionSort(int a[],int N)
//{
//	int temp;
//	int i,p;
//	for(p=1;p<N;p++)
//	{
//		temp=a[p];
//		for(i=p;i>0 && a[i-1]>temp;i--)
//			a[i]=a[i-1];
//		a[i]=temp;
//	}
//}
