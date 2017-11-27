#include<iostream>
#include<stdio.h>
using namespace std;
#define N 50  //�������

template<class T>
class MinHeap {
private:
	T *mHeap;  //����
	int mCap;  //�ܵ�����
	int mSize;  //ʵ������
private:
	void filter_down(int start);  //Ԫ���³�
	void filter_up(int x);  //Ԫ���ϸ�
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
MinHeap<T>::~MinHeap()   //��������
{
	mSize = 0;
	mCap = 0;
	delate[] mHeap;
}
template<class T>
void MinHeap<T>::filter_up(int x)   //�ϸ�
{
	int i;
	for (i = mSize; mHeap[(i-1)/2] > x && i != 0; i = (i-1) / 2)
		mHeap[i] = mHeap[(i-1) / 2];
	mHeap[i] = x;
}

template<class T>
int MinHeap<T>::insert(T data)  //��β������һ��Ԫ��
{
	if (mSize == mCap)
		return -1;
	mHeap[mSize] = data;
	filter_up(data);
	mSize++;
	return 0;
}

template<class T>
void MinHeap<T>::filter_down(int start)  //����(percolate down)
{
	int c = start;  //��ǰ�ڵ�λ��
	int left = 2 * c + 1;
	T tmp = mHeap[c];  //��ǰ�ڵ�keyֵ

	while (left <= mSize-1)
	{
		if (left < mSize-1 && mHeap[left] > mHeap[left + 1])   //����������ȡС��
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
int MinHeap<T>::remove(T data)   //ɾ��һ��Ԫ��
{
	int index;
	if (mSize == 0)
		return -1;
	for (index = 0; index < mSize; index++)
		if (data == mHeap[index])
			break;
	if (index == mSize)
	{
		cout << "ERROR ���޴�����" << endl;
		return -1;
	}	
	mSize--;
	mHeap[index] = mHeap[mSize];  //�����һ��Ԫ�����ɾ��Ԫ�ص�λ��
	filter_down(index);   //����
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

	cout << "ԭ���飺" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		tree->insert(a[i]);
	}
	cout << endl << "��С�ѣ�" << endl;
	tree->print();
	cout << endl;
	
	while (1)
	{
		cout << "����һ��Ԫ�صļ�ֵ��" << endl;
		int x;
		cin >> x;
		tree->insert(x);
		tree->print();

		cout << "\nɾ��һ��Ԫ�صļ�ֵ��" << endl;
		int d;
		cin >> d;
		tree->remove(d);
		tree->print();
		cout << endl;
	}
	return 0;
}

