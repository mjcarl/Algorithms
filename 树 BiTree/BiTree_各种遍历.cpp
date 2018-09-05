#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;       //*BiTree = struct BiNode

void CreateTree(BiTree &T)   //建立二叉树，先序遍历输入，孩子为空输入'p'
{
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
        CreateTree(T->lchild);  //先序
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

void PreOrder2(BiTree T)  //非递归的前序遍历
{
    stack<BiTree>s;
    BiTree b=T;
    while(b!=nullptr || !s.empty())
    {
        while(b!=nullptr)
        {
            cout<<b->data<<" ";
            s.push(b);
            b=b->lchild;
        }
        if(!s.empty())
        {
            b=s.top();
            s.pop();
            b=b->rchild;
        }
    }
    cout<<endl;
}

void InOrder2(BiTree T)
{
    stack<BiTree>s;
    BiTree b=T;
    while(b!=nullptr || !s.empty())
    {
        while(b!=nullptr)
        {
            s.push(b);
            b=b->lchild;
        }
        if(!s.empty())
        {
            b=s.top();
            s.pop();
            cout<<b->data<<" ";
            b=b->rchild;
        }
    }
    cout<<endl;
}
//要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；
//或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
//若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。

void PostOrder2(BiTree T)  //在后序遍历中，要保证左孩子和右孩子都已被访问并且左孩子在右孩子前访问才能访问根结点
{
    stack<BiTree>s;
    BiTree cur;
    BiTree pre=nullptr;
    s.push(T);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==nullptr && cur->rchild==nullptr)
        || (pre!=nullptr && (pre==cur->lchild || pre==cur->rchild)))
        {
            cout<<cur->data<<" ";
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->rchild!=nullptr)
                s.push(cur->rchild);   //先放右节点再放左节点，保证出栈是先左后右
            if(cur->lchild!=nullptr)
                s.push(cur->lchild);
        }
    }
    cout<<endl;
}

void LevelOrder(BiTree T) //层序遍历，用队列
{
    if(T==NULL)
        return ;
    queue<BiTree>q;
    q.push(T);
    while(!q.empty())
    {
        BiTree b;
        b=q.front();
        q.pop();
        cout<<b->data<<" ";
        if(b->lchild!=nullptr)
            q.push(b->lchild);
        if(b->rchild!=nullptr)
            q.push(b->rchild);
    }
    cout<<endl;
}

int main()
{
    BiTree T;
    CreateTree(T);
    printf("先序遍历\n");
    PreOrder(T);
	printf("\n");
    PreOrder2(T);
	printf("中序遍历\n");
	InOrder(T);
	printf("\n");
    InOrder2(T);
	printf("后序遍历\n");
	PostOrder(T);
	printf("\n");
    PostOrder2(T);
    cout<<"层序遍历"<<endl;
    LevelOrder(T);
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
