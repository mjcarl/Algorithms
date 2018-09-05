#include<bits/stdc++.h>
using namespace std;

typedef struct student
{
    int data;
    struct student *next;
}node;

node *create()
{
    node *head,*p,*s;
    int x,cycle=1;
    head=(node*)malloc(sizeof(node));  //建立一个空节点
    p=head;
    while(cycle)
    {
        cout<<"input the data: "<<endl;
        cin>>x;
        if(x!=0)
        {
            s=(node *)malloc(sizeof(node));
            s->data=x;
            p->next=s;
            p=s;
        }
        else
            cycle=0;
    }
    head=head->next;
    p->next=nullptr;
    return head;
}

node *delete_elm(node *head, int num)
{
    node *p1,*p2;
    p1=head;
    if(p1->data==num)
    {
        p2=p1->next;
        free(p1);
        p1=nullptr;
        return p2;
    }
    else
    {
        p2=p1;
        p1=p1->next;
        while(p1!=nullptr)
        {
            if(p1->data==num)
            {
                p2->next=p1->next;
                free(p1);
                p1=nullptr;
                break;
            }
            p2=p1;
            p1=p1->next;
        }
    }
    return head;
}

node *insert(node *head,int i,int num) //插入到第i个节点后面
{
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->data = num;
    q=head;
    if(i==0)  //插入到头节点之前
    {
        p->next=head;
        return p;
    }
    for(int m=1;m<i && q!=nullptr;i++)
    {
        q=q->next;
    }
    if(q!=nullptr)
    {
        p->next=q->next;
        q->next=p;
    }
    else
    {
        free(p);
        p=nullptr;
        cout<<"输入越界！"<<endl;
    }
    return head;
}
