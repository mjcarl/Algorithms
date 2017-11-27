#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//------栈，限制插入和删除只能在一个位置上的表(LIFO)

typedef struct Stack   //栈的结构体,链表实现(节省空间，不如数组好实现)
{
    int Element;
    struct Stack *next;
}*stack;

int isEmpty(stack s)
{
	return s->next == NULL;
}

int pop(stack s)
{
	int re=-999;
	stack p;
	if(isEmpty(s))
		printf("ERROR\n");
	else
	{
		p=s->next;
		s->next=s->next->next;
		re=p->Element;
		free(p);
	}
	return re;
}

void push(int x,stack s)
{
	stack p;
	p=(stack)malloc(sizeof(struct Stack));
	if(p == NULL)
		printf("ERROR\n");
	else
	{
		p->Element=x;
		p->next=s->next;
		s->next=p;
	}
}

void makeEmpty(stack s)
{
	if(s==NULL)
		printf("ERROR\n");
	else
		while(!isEmpty(s))
		{
			pop(s);
		}
}
stack create(void)
{
	stack s;
	s=(stack)malloc(sizeof(struct Stack));
	if(s == NULL)
		printf("ERROR\n");
	s->next=NULL;
	makeEmpty(s);
	return s;
}


//-------------------
/*
typedef struct Stack   //栈的结构体，数组实现
{
    int Vex[1000];   //大小固定范围内
    int top;
}*stack;

void my_empty_s(stack s)   //清空栈
{
    s->top=-1;
}

stack createstack()   //建立一个空栈
{
    stack s;
    s=(struct Stack *)malloc(sizeof(struct Stack));
    my_empty_s(s);
    return s;
}

void push_s(stack s,int x)  //元素进栈
{
    s->Vex[++s->top]=x;
}

*/