#include<bits/stdc++.h>
using namespace std;

typedef struct student
{
    int data;
    struct student *next;
}node;

typedef struct linkqueue
{
    node *first,*rear;
}Queue;

Queue *insert(Queue *hq,int x)  //尾部插入元素
{
    node *s;
    s=(node *)malloc(sizeof(node));
    s->data=x;
    s->next=nullptr;
    if(hq->rear==nullptr)
    {
        hq->first=s;
        hq->rear=s;
    }
    else
    {
        hq->rear->next=s;
        hq->rear=s;
    }
    return hq;
}

Queue *del(Queue *hq)   //头部输出元素
{
    node *p;  int x;
    if(hq==nullptr)
    {
        cout<<"error!"<<endl;
        return hq;
    }
    else
    {
        x=hq->first->data;
        cout<<"output: "<<x<<endl;
        p=hq->first;
        if(hq->first==hq->rear)
        {
            hq->first=nullptr;
            hq->rear=nullptr;
        }
        else
        {
            hq->first=hq->first->next;
            free(p);
            p=nullptr;
        }
        return hq;
    }
}
