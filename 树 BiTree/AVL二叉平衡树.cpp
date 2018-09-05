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

static Position SingleRotateWithLeft(Position K2)   //左到右的单旋转
{
	Position K1 = K2->left;

	K2->left = K1->right;
	K1->right = K2;

	K2->height = Max(height(K2->left),height(K2->right)) + 1;
	K1->height = Max(height(K1->left),height(K1->right)) + 1;

	return K1;  //new root
}

static Position SingleRotateWithRight(Position K2)   //右到左的单旋转
{
	Position K1 = K2->right;

	K2->right = K1->left;
	K1->left = K2;

	K2->height = Max(height(K2->left),height(K2->right)) + 1;
	K1->height = Max(height(K1->left),height(K1->right)) + 1;

	return K1;  //new root
}

static Position DoubleRotateWithLeft(Position K3)   //左到右的双旋转  **先用右到左单旋转再到左到右单旋转**   妙！
{
	K3->left = SingleRotateWithRight(K3->left);  //Rotate between K1 and K2   注意是Right

	return SingleRotateWithLeft(K3);    //Rotate between K3 and K2    注意是Left
}

AvlTree Insert(int x, AvlTree T)   //新建二叉平衡树   没有相同的元素 
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
			if(x<T->left->value)  //插到左孩子的左边
				SingleRotateWithLeft(T);
			else
				DoubleRotateWithLeft(T);    //插到左孩子的右边
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
	T->height = Max(height(T->left),height(T->right)) + 1;  //更新高度
	return T;
}








