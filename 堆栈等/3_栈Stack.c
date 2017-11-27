#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//------ջ�����Ʋ����ɾ��ֻ����һ��λ���ϵı�(LIFO)

typedef struct Stack   //ջ�Ľṹ��,����ʵ��(��ʡ�ռ䣬���������ʵ��)
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
typedef struct Stack   //ջ�Ľṹ�壬����ʵ��
{
    int Vex[1000];   //��С�̶���Χ��
    int top;
}*stack;

void my_empty_s(stack s)   //���ջ
{
    s->top=-1;
}

stack createstack()   //����һ����ջ
{
    stack s;
    s=(struct Stack *)malloc(sizeof(struct Stack));
    my_empty_s(s);
    return s;
}

void push_s(stack s,int x)  //Ԫ�ؽ�ջ
{
    s->Vex[++s->top]=x;
}

*/