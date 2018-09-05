#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;       //*BiTree = struct BiNode

void CreateTree(BiTree &T)   //����������������������룬����Ϊ������'p'
{
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
        CreateTree(T->lchild);  //����
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

void PreOrder2(BiTree T)  //�ǵݹ��ǰ�����
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
//Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
//����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
//�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�

void PostOrder2(BiTree T)  //�ں�������У�Ҫ��֤���Ӻ��Һ��Ӷ��ѱ����ʲ����������Һ���ǰ���ʲ��ܷ��ʸ����
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
                s.push(cur->rchild);   //�ȷ��ҽڵ��ٷ���ڵ㣬��֤��ջ���������
            if(cur->lchild!=nullptr)
                s.push(cur->lchild);
        }
    }
    cout<<endl;
}

void LevelOrder(BiTree T) //����������ö���
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
    printf("�������\n");
    PreOrder(T);
	printf("\n");
    PreOrder2(T);
	printf("�������\n");
	InOrder(T);
	printf("\n");
    InOrder2(T);
	printf("�������\n");
	PostOrder(T);
	printf("\n");
    PostOrder2(T);
    cout<<"�������"<<endl;
    LevelOrder(T);
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
