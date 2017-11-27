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

BiTree Insert(int x,BiTree T)   //����Ԫ�ص�����������Tָ������
{
	if(T==NULL)
	{
		T=(struct BiNode*)malloc(sizeof(struct BiNode));   //����д��sizeof(BiTree)
		if(T==NULL)
			printf("error\n");
		else
		{
			T->data=x;
			T->lchild=NULL;
			T->rchild=NULL;
		}
	}
	else if(x<T->data)   //�ݹ�ֱ��TΪ�գ�����Ҫ�����λ��
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
	else   //�ҵ�Ҫɾ���Ľڵ�
	{	
		if (T->lchild != NULL && T->rchild != NULL)
		{
			//���������е���Сֵ�ڵ㣬ʹ����x����
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
			free(Tmp);  //�ͷŽڵ�ռ�
		}
	}
	return T;
}
void visit(BiTree T)
{
	printf("%d ", T->data);
}

void InOrder(BiTree T)   //����������
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
	printf("����7��Ԫ�أ�\n");
	T = (struct BiNode*)malloc(sizeof(BiTree));
	T = NULL;
	while (i < 7)
	{
		scanf("%d",&x);
		T=Insert(x,T);
		i++;
	}
	printf("�����\n");
	InOrder(T);
	printf("\n����һ��Ҫɾ����Ԫ�أ�\n");
	scanf("%d", &x);
	T = Delete(x, T);
	printf("�����\n");
	InOrder(T);
	printf("\n");
	return 0;
}