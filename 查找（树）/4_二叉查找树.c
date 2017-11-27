#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

typedef struct BiNode
{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;  

BiTree Insert(int x,BiTree T)   //插入元素到二叉查找树里，T指向树根
{
	if(T==NULL)
	{
		T=(struct BiNode*)malloc(sizeof(struct BiNode));   //不能写成sizeof(BiTree)
		if(T==NULL)
			printf("error\n");
		else
		{
			T->data=x;
			T->lchild=NULL;
			T->rchild=NULL;
		}
	}
	else if(x<T->data)   //递归直至T为空，即需要插入的位置
		T->lchild=Insert(x,T->lchild);
	else if(x>T->data)
		T->rchild=Insert(x,T->rchild);
	return T;
}
BiTree FindMin(BiTree T)
{
	if (T == NULL)
		return NULL;
	if (T->lchild == NULL)
		return T;
	else
		FindMin(T->lchild);
	
}
BiTree Delete(int x, BiTree T)
{
	BiTree Tmp;
	if (x < T->data)
		T->lchild = Delete(x, T->lchild);
	else if (x > T->data)
		T->rchild = Delete(x, T->rchild);
	else   //找到要删除的节点
	{	
		if (T->lchild != NULL && T->rchild != NULL)
		{
			//找右子树中的最小值节点，使其与x交换
			Tmp = FindMin(T->rchild);
			T->data = Tmp->data;
			T->rchild = Delete(Tmp->data, T->rchild);
		}
		else
		{
			Tmp = T;
			if (T->rchild == NULL)
				T = T->lchild;
			else if (T->lchild == NULL)
				T = T->rchild;
			free(Tmp);  //释放节点空间
		}
	}
	return T;
}
void visit(BiTree T)
{
	printf("%d ", T->data);
}

void InOrder(BiTree T)   //中序遍历输出
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
int main()
{
	int i = 0, x;
	BiTree T;
	printf("输入7个元素：\n");
	T = (struct BiNode*)malloc(sizeof(BiTree));
	T = NULL;
	while (i < 7)
	{
		scanf("%d",&x);
		T=Insert(x,T);
		i++;
	}
	printf("排序后：\n");
	InOrder(T);
	printf("\n输入一个要删除的元素：\n");
	scanf("%d", &x);
	T = Delete(x, T);
	printf("排序后：\n");
	InOrder(T);
	printf("\n");
	return 0;
}