#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

int maxlen = 0;

int height(BiTree T)  //核心思想：后序遍历，便于比较两个孩子的信息
{
	if (T == nullptr)
		return -1;
	int leftHeight = height(T->lchild) + 1;  //节点从左边走的最大深度
	int rightHeight = height(T->rchild) + 1;  //节点从右边走的最大深度
	int maxHeight = leftHeight + rightHeight;  //连接左右两边
	maxlen = maxlen > maxHeight ? maxlen : maxHeight;  //更新最长距离
	return leftHeight > rightHeight ? leftHeight : rightHeight;  //返回最大深度
}

int TreeDepth(BiTree T)   //求二叉树的深度
{
	if (T == nullptr)
		return -1;   //只有根节点认为树的深度为0
	int nLeft = TreeDepth(T->lchild);
	int nRight = TreeDepth(T->rchild);

	return nLeft > nRight ? nLeft + 1 : nRight + 1;
}

bool isAVL = true;
int AVL_Height(BiTree T)  //平衡二叉树要求二叉树中任意结点的左右子树高度相差不超过1
{
    if(T==nullptr)
    {
        return -1;
    }
    int leftHeight = AVL_Height(T->lchild);
    int rightHeight = AVL_Height(T->rchild);
    if( abs(leftHeight-rightHeight) > 1 )
        isAVL = false;

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
