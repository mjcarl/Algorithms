#include<iostream>
#include"Linklist.h"

using namespace std;

Linklist::Linklist()  //构造函数
{
	Head = new Node;
	Head->data = 0;
	Head->next = NULL;
}

void Linklist::CreateList(int n)  //尾插入法创建链表
{
	Node *p,*q;
	int tmp;
	cout << "请依次输入" << n << "个链表的值: ";
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (i == 0)
		{
			Head->data = tmp;
			p = Head;
		}
		else
		{
			q = new Node;
			q->data = tmp;
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}
}

void Linklist::Insert(int i, int e)   //插入到第i个节点后面
{
	Node *tmp;
	tmp = Head;
	int j;
	for (j = 0; j < i-1 && tmp != NULL; j++)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL || j > i-1)
	{
		cout << "error input!" << endl;
	}
	else
	{
		Node *p = new Node;
		p->data = e;
		p->next = tmp->next;
		tmp->next = p;
	}
}

int Linklist::Delete(int i)  //删除第i个节点并返回值
{
	Node *p;
	int j, del;
	p = Head;
	if (i == 0)
	{
		Head = Head->next;
		del = p->data;
		delete p;
		return del;
	}
	for (j = 0; j < i - 2 && p->next != NULL; j++)  //找到要被删除的节点的前一个节点
	{
		p = p->next;
	}
	if (p == NULL || p->next == NULL)
	{
		cout << "error input delete!" << endl;
		return -1;
	}
	//删除p的next节点
	Node *tmp, *q;
	q = p->next;
	tmp = p->next->next;
	del = q->data;
	delete q;
	p->next = tmp;
	return del;
}

int Linklist::ListLength()
{
	Node *p;
	int i=0;
	p = Head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
		i++;
	}
	cout << endl << "length = " << i << endl;
	return i;
}
