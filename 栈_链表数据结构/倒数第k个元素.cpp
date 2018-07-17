#include<iostream>
using namespace std;

struct ListNode {
	int m_value;
	ListNode* m_pNext;
};

ListNode* FindK(ListNode* pHead, unsigned int k)
{
	if (pHead == NULL && k < 1)
		return NULL;
	ListNode* pA = pHead;  //pAÏÈ×ßk-1²½
	ListNode* pB = pHead;
	while (k - 1 > 0)
	{
		if (pB->m_pNext == NULL)
			return NULL;
		pB = pB->m_pNext;
		--k;
	}
	while (pB->m_pNext != NULL)
	{
		pB = pB->m_pNext;
		pA = pA->m_pNext;
	}
	return pA;
}