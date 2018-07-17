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
	Listnode* prenode = NULL;  //ǰһ�����
	while(node!=NULL)
	{
		Listnode* pNext = node->m_next;   //��һ�����
		if(pNext == NULL)
			revsList = node;
		node->m_next = prenode;  //����ǰ�Ľ��ָ��ָ��ǰһ�����
		prenode = node;
		node = pNext;
	}	
	return revsList;
}