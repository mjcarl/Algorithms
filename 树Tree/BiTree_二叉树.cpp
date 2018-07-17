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

void CreateTree(BiTree &T)   //����������
{
    //fflush(stdin);   //ˢ�±�׼���뻺�������������뻺�����Ķ���
    char data;
    scanf("%c",&data);
    if(data=='p')      //����pΪ�ս��
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

void PreOrder(BiTree T)  //�������
{
    if(T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)   //�������
{
	if(T!=NULL)
    {
		InOrder(T->lchild);		
        visit(T);    
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)    //�������
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
    printf("�������\n");
    PreOrder(T);
	printf("\n");
	printf("�������\n");
	InOrder(T);
	printf("\n");
	printf("�������\n");
	PostOrder(T);
	printf("\n");
    return 0;
}

/*   
typedef struct treenode *ptrtonode;   //��ͨ�������ɣ�UNIXĿ¼��
struct treenode
{
	int element;
	ptrtonode firstchild;	 //��һ������
	ptrtonode nextsibling;   //��һ���ֵ�
}
*/

