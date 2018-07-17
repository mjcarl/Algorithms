#include<iostream>
using namespace std;

struct Listnode{
	int m_value;
	Listnode* m_next;
};

Listnode* ReverseList(Listnode* head)
{
	Listnode* revsList = NULL;
	Listnode* node = head;
	Listnode* prenode = NULL;  //前一个结点
	while(node!=NULL)
	{
		Listnode* pNext = node->m_next;   //后一个结点
		if(pNext == NULL)
			revsList = node;
		node->m_next = prenode;  //将当前的结点指针指向前一个结点
		prenode = node;
		node = pNext;
	}	
	return revsList;
}