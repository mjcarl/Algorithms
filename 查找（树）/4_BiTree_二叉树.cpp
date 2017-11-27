#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>


typedef struct BiNode
{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;       //*BiTree = struct BiNode

void CreateTree(BiTree &T)   //建立二叉树
{
    //fflush(stdin);   //刷新标准输入缓冲区，丢弃输入缓冲区的东西
    char data;
    scanf("%c",&data);
    if(data=='p')      //输入p为空结点
    {
        T=NULL;
    }
    else
    {
        T=(BiNode *)malloc(sizeof(BiNode));
        T->data=data;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

void visit(BiTree T)
{
    if(T->data!='p')
        printf("%c ",T->data);
}

void PreOrder(BiTree T)  //先序遍历
{
    if(T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)   //中序遍历
{
	if(T!=NULL)
    {
		InOrder(T->lchild);		
        visit(T);    
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)    //后序遍历
{
	if(T!=NULL)
    {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
        visit(T);            
    }
}

int main()
{
    BiTree T;
    CreateTree(T);
    printf("先序遍历\n");
    PreOrder(T);
	printf("\n");
	printf("中序遍历\n");
	InOrder(T);
	printf("\n");
	printf("后序遍历\n");
	PostOrder(T);
	printf("\n");
    return 0;
}

/*   
typedef struct treenode *ptrtonode;   //普通树的生成（UNIX目录）
struct treenode
{
	int element;
	ptrtonode firstchild;	 //第一个孩子
	ptrtonode nextsibling;   //下一个兄弟
}
*/

