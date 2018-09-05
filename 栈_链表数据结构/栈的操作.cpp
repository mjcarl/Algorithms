#include<bits/stdc++.h>
using namespace std;

typedef struct student
{
    int data;
    struct student *next;
}node;

typedef struct stackqueue
{
    node *end_of_stack,*top;
}Stack;

Stack *push(Stack *hq, int x)
{
    node *s;
    s=(node *)malloc(sizeof(node));
    s->data=x;
    s->next=nullptr;
    if(hq->end_of_stack==nullptr)
    {
        hq->end_of_stack=s;
        hq->top=s;
    }
    else
    {
        hq->top->next=s;
        hq->top=s;
    }
    return hq;
}

Stack *pop(Stack *hq)
{
     if(hq->end_of_stack==nullptr)
     {
         cout<<"error!"<<endl;
     }
     else
     {
         int x;
         node *p;
         x=hq->top->data;
         cout<<"output: "<<x<<endl;
         p=hq->end_of_stack;
         if(hq->end_of_stack==hq->top)
         {
             hq->end_of_stack=nullptr;
             hq->top=nullptr;         
         }
         else
         {
             while(p->next!=hq->top)
                p=p->next;
             hq->top=p;
             hq->top->next=nullptr;
         }
         free(p);
         p=nullptr;
     }
     return hq;
}
