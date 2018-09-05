#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

BiTree lowestAncestor(BiTree head, BiTree o1, BiTree o2)
{
	if (head == nullptr || head == o1 || head == o2)
	{
		return head;
	}
	BiTree left = lowestAncestor(head->lchild, o1, o2);  //�������
	BiTree right = lowestAncestor(head->rchild, o1, o2);
	if (left != nullptr && right != nullptr)  //���Һ��Ӷ��ֱ��ҵ���o1��o2�����ʱ��headΪ��С���ڵ�
	{
		return head;
	}
	return left != nullptr ? left : right;
}

int TreeDepth(BiTree T)   //������������
{
	if (T == nullptr)
		return -1;   //ֻ�и��ڵ���Ϊ�������Ϊ0
	int nLeft = TreeDepth(T->lchild);
	int nRight = TreeDepth(T->rchild);

	return nLeft > nRight ? nLeft + 1 : nRight + 1;
}