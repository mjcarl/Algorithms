#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

queue<BiTree>q;
bool isCompleteTree(BiTree T)
{
    if(T==nullptr)
    {
        return true;
    }
    bool isSingle = false;
    q.push(T);
    while(!q.empty())
    {
        BiTree t;
        t=q.front();
        q.pop();
        if(isSingle==true && (t->lchild!=nullptr || t->rchild!=nullptr))   //��ʱ������Ҷ�ӽڵ�
        {
            return false;
        }
        if(t->lchild!=nullptr && t->rchild!=nullptr)   //���Ҷ��к��ӣ������
        {
            q.push(t->lchild);
            q.push(t->rchild);
        }
        else if(t->lchild!=nullptr)  //ֻ�����ӣ����������нڵ㶼������Ҷ�ӽڵ�
        {
            q.push(t->lchild);
            isSingle = true;
        }
        else if(t->rchild!=nullptr)  //ֻ���ҽڵ㣬ֱ�ӷ���false
        {
            return false;
        }
        else  //Ҷ�ӽڵ�
        {
            isSingle = true;
        }
    }
    return true;
}
