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
	BiTree left = lowestAncestor(head->lchild, o1, o2);  //后序遍历
	BiTree right = lowestAncestor(head->rchild, o1, o2);
	if (left != nullptr && right != nullptr)  //左右孩子都分别找到了o1和o2，则此时的head为最小父节点
	{
		return head;
	}
	return left != nullptr ? left : right;
}

int TreeDepth(BiTree T)   //求二叉树的深度
{
	if (T == nullptr)
		return -1;   //只有根节点认为树的深度为0
	int nLeft = TreeDepth(T->lchild);
	int nRight = TreeDepth(T->rchild);

	return nLeft > nRight ? nLeft + 1 : nRight + 1;
}