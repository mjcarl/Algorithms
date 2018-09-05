#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

int maxlen = 0;

int height(BiTree T)  //����˼�룺������������ڱȽ��������ӵ���Ϣ
{
	if (T == nullptr)
		return -1;
	int leftHeight = height(T->lchild) + 1;  //�ڵ������ߵ�������
	int rightHeight = height(T->rchild) + 1;  //�ڵ���ұ��ߵ�������
	int maxHeight = leftHeight + rightHeight;  //������������
	maxlen = maxlen > maxHeight ? maxlen : maxHeight;  //���������
	return leftHeight > rightHeight ? leftHeight : rightHeight;  //����������
}

int TreeDepth(BiTree T)   //������������
{
	if (T == nullptr)
		return -1;   //ֻ�и��ڵ���Ϊ�������Ϊ0
	int nLeft = TreeDepth(T->lchild);
	int nRight = TreeDepth(T->rchild);

	return nLeft > nRight ? nLeft + 1 : nRight + 1;
}

bool isAVL = true;
int AVL_Height(BiTree T)  //ƽ�������Ҫ�������������������������߶�������1
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
