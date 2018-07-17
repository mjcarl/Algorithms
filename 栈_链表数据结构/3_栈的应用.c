#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//------����һ�γ����ж�{ [ ( ) ] }�Ƿ��Ӧ--------------

typedef struct Stack   //ջ�Ľṹ�壬����ʵ��
{
    char Vex[1000];   //��С�̶���Χ��
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

void push(stack s,char x)  //Ԫ�ؽ�ջ
{
    s->Vex[++s->top]=x;
}
char pop(stack s)   //��ջһ��Ԫ�ز����ظ�Ԫ��
{
	char p;
	if(s->top>=0)
	{
		p=s->Vex[s->top];
		s->top--;
		return p;
	}
	else
		printf("error\n");
	return -1;
}
void input(stack s)
{
	char c;
	int tmp=0;
	c=getchar();
	while(c!='$')
	{
		//printf("%c",c);
		c=getchar();
		if(c=='{' || c=='[' || c=='(')
			push(s,c);
		if(c=='}' && '{'!=pop(s))
		{
			tmp=1;
			c='$';
		}
		if(c==']' && '['!=pop(s))
		{
			tmp=1;
			c='$';
		}
		if(c==')' && '('!=pop(s))
		{
			tmp=1;
			c='$';
		}
	}
	if(s->top==-1 && tmp==0)
		printf("\nRIGHT!\n");
	else
		printf("\nERROR!\n");
}

void main(void)
{
	stack s;
	s=createstack();
	input(s);
}






