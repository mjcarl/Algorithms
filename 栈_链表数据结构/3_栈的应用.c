#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//------输入一段程序，判断{ [ ( ) ] }是否对应--------------

typedef struct Stack   //栈的结构体，数组实现
{
    char Vex[1000];   //大小固定范围内
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

void push(stack s,char x)  //元素进栈
{
    s->Vex[++s->top]=x;
}
char pop(stack s)   //出栈一个元素并返回该元素
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






