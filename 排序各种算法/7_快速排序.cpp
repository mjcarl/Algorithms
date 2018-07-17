#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//------快速排序（O(N logN)）---------
//------枢纽元-----------      //注意边界的选取！！！  注意重复元素多不多

static int p=0;
void print(int a[],int N)
{
	int i;
	for(i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
inline void swap(int &a,int &b) //用内联函数  引用
{
	int t;
	t=a;
	a=b;
	b=t;
}

int median3(int a[],int low,int high)   //实现三中数中值分割法/三取样切分
{
	int center=(low+high)/2;
	if(a[low]>a[center])
		swap(a[low],a[center]);
	if(a[low]>a[high])
		swap(a[low],a[high]);
	if(a[center]>a[high])
		swap(a[center],a[high]);
	swap(a[center],a[high-1]);   //因为a[high]一定不小于a[center]，排序时只考虑a[high-1]前的元素
	return a[high-1];      //返回需要移动到正确位置的枢纽元值
}
inline void compare(int a[],int low,int high)
{
	if(a[low]>a[high])
		swap(a[low],a[high]);
}
static void QuickSort(int a[],int low,int high)   //主程序,重复元素较少时
{
	int i,j;
	int pivot;
	
	i=low;  //警示标记点
	j=high-1;
	if(i<j) //剩余元素至少为3个
	{
		pivot=median3(a,low,high);  //三取样切分，取中位数，效果最好  ************************  当数列有序时用这个最好
	
		while(1)
		{
			while(a[++i]<pivot)
			{ }
			while(a[--j]>pivot)
			{ }
			if(i<j)  //i还在j的前面
				swap(a[i],a[j]);
			else
				break;
		}
		swap(a[i],a[high-1]);   //restore pivot
		QuickSort(a,low,i-1);   //注意边界
		QuickSort(a,i+1,high);
	}
	else if(i==j)  //只剩两个元素的排序
		compare(a,i,j+1);
}

static void Quick3way(int a[],int low,int high)  //含有较多重复元素时，三向切分的快速排序法
{
	if(low>=high)
		return;
	int lt=low,i=low+1,gt=high;
	int pivot = a[low];  //pivot选在最左边
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
	//现在 a[low..lt-1]<pivot=a[lt..gt]<a[gt+1,,high]
	Quick3way(a,low,lt-1);
	Quick3way(a,gt+1,high);
}
int main(void)
{
	static int n=0;
	int a[100];
	cout<<"快速排序---请输入数组，输入-1停止"<<endl;
	cin>>a[0];
	while(a[n]!=-1)
		cin>>a[++n];
	//int x[10]={5,8,2,1,7,9,0,18,4,23};
	//random_shuffle(x,x+10);  //打乱数组
	cout<<"========================="<<endl;
	print(a,n);
	QuickSort(a,0,n-1);  //n个有效数字
	//Quick3way(a,0,n-1);
	cout<<"快速排序后："<<endl;
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
