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
        if(isSingle==true && (t->lchild!=nullptr || t->rchild!=nullptr))   //此时必须是叶子节点
        {
            return false;
        }
        if(t->lchild!=nullptr && t->rchild!=nullptr)   //左右都有孩子，入队列
        {
            q.push(t->lchild);
            q.push(t->rchild);
        }
        else if(t->lchild!=nullptr)  //只有左孩子，则后面的所有节点都必须是叶子节点
        {
            q.push(t->lchild);
            isSingle = true;
        }
        else if(t->rchild!=nullptr)  //只有右节点，直接返回false
        {
            return false;
        }
        else  //叶子节点
        {
            isSingle = true;
        }
    }
    return true;
}
