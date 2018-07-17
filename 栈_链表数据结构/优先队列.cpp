#include<iostream>
#include<stdio.h>
using namespace std;
#define N 50  //最大容量

template<class T>
class MinHeap {
private:
	T *mHeap;  //数据
	int mCap;  //总的容量
	int mSize;  //实际容量
private:
	void filter_down(int start);  //元素下沉
	void filter_up(int x);  //元素上浮
public:
	MinHeap();
	MinHeap(int cap);
	~MinHeap();

	int remove(T data);
	int insert(T data);
	void print();
};
template<class T>
MinHeap<T>::MinHeap()
{
	new (this)MinHeap(N);
}
template<class T>
MinHeap<T>::MinHeap(int cap)
{
	mSize = 0;
	mCap = cap;
	mHeap = new T[mCap];
}
template<class T>
MinHeap<T>::~MinHeap()   //析构函数
{
	mSize = 0;
	mCap = 0;
	delate[] mHeap;
}
template<class T>
void MinHeap<T>::filter_up(int x)   //上浮
{
	int i;
	for (i = mSize; mHeap[(i-1)/2] > x && i != 0; i = (i-1) / 2)
		mHeap[i] = mHeap[(i-1) / 2];
	mHeap[i] = x;
}

template<class T>
int MinHeap<T>::insert(T data)  //从尾部插入一个元素
{
	if (mSize == mCap)
		return -1;
	mHeap[mSize] = data;
	filter_up(data);
	mSize++;
	return 0;
}

template<class T>
void MinHeap<T>::filter_down(int start)  //下滤(percolate down)
{
	int c = start;  //当前节点位置
	int left = 2 * c + 1;
	T tmp = mHeap[c];  //当前节点key值

	while (left <= mSize-1)
	{
		if (left < mSize-1 && mHeap[left] > mHeap[left + 1])   //两个孩子里取小的
			left++;
		if (tmp > mHeap[left])
		{
			mHeap[c] = mHeap[left];
			c = left;
			left = 2 * c + 1;
		}
		else
			break;
	}
	mHeap[c] = tmp;
}

template<class T>
int MinHeap<T>::remove(T data)   //删除一个元素
{
	int index;
	if (mSize == 0)
		return -1;
	for (index = 0; index < mSize; index++)
		if (data == mHeap[index])
			break;
	if (index == mSize)
	{
		cout << "ERROR 查无此数！" << endl;
		return -1;
	}	
	mSize--;
	mHeap[index] = mHeap[mSize];  //将最后一个元素填补到删除元素的位置
	filter_down(index);   //下滤
	return 0;
}
template <class T>
void MinHeap<T>::print()
{
     for (int i = 0; i<mSize; i++)
         cout << mHeap[i] << " ";
}
int main()
{
	int a[] = { 50,80,20,10,70,90,40,33,75,102 };
	int i=0;
	int len = (sizeof(a)) / (sizeof(a[0]));
	MinHeap<int>* tree = new MinHeap<int>();

	cout << "原数组：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		tree->insert(a[i]);
	}
	cout << endl << "最小堆：" << endl;
	tree->print();
	cout << endl;
	
	while (1)
	{
		cout << "插入一个元素的键值：" << endl;
		int x;
		cin >> x;
		tree->insert(x);
		tree->print();

		cout << "\n删除一个元素的键值：" << endl;
		int d;
		cin >> d;
		tree->remove(d);
		tree->print();
		cout << endl;
	}
	return 0;
}

