#include<stdio.h>

typedef struct AvlNode *AvlTree;
typedef struct AvlNode *Position;

struct AvlNode
{
	int value;
	AvlTree left;
	AvlTree right;
	int height;

};

static Position SingleRotateWithLeft(Position K2)   //���ҵĵ���ת
{
	Position K1 = K2->left;

	K2->left = K1->right;
	K1->right = K2;

	K2->height = Max(height(K2->left),height(K2->right)) + 1;
	K1->height = Max(height(K1->left),height(K1->right)) + 1;

	return K1;  //new root
}

static Position SingleRotateWithRight(Position K2)   //�ҵ���ĵ���ת
{
	Position K1 = K2->right;

	K2->right = K1->left;
	K1->left = K2;

	K2->height = Max(height(K2->left),height(K2->right)) + 1;
	K1->height = Max(height(K1->left),height(K1->right)) + 1;

	return K1;  //new root
}

static Position DoubleRotateWithLeft(Position K3)   //���ҵ�˫��ת  **�����ҵ�����ת�ٵ����ҵ���ת**   �
{
	K3->left = SingleRotateWithRight(K3->left);  //Rotate between K1 and K2   ע����Right

	return SingleRotateWithLeft(K3);    //Rotate between K3 and K2    ע����Left
}

AvlTree Insert(int x, AvlTree T)   //�½�����ƽ����   û����ͬ��Ԫ�� 
{
	if(T == NULL)
	{
		T = (struct AvlNode*)malloc(sizeof(struct AvlNode));
		if(T == NULL)
			printf("error!\n");
		else{
			T->value = x;
			t->height = 0;
			t->left = T->right = NULL;
		}
	}
	else if(x < T->value)
	{
		T->left = Insert(x,T->left);
		if(height(T->left) - height(T->right) == 2)
		{
			if(x<T->left->value)  //�嵽���ӵ����
				SingleRotateWithLeft(T);
			else
				DoubleRotateWithLeft(T);    //�嵽���ӵ��ұ�
		}		
	}
	else if(x > T->value)
	{
		T->right = Insert(x,T->right);
		if(height(T->right) - height(T->left) == 2)
		{
			if(x<T->right->value)
				SingleRotateWithRight(T);
			else
				DoubleRotateWithRight(T);
		}		
	}
	T->height = Max(height(T->left),height(T->right)) + 1;  //���¸߶�
	return T;
}








