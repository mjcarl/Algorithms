#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define PI 3.141592654
//--------------------chapter 3 栈与队列--------------------

//建立动态链表

#define LEN sizeof(struct Student)
int n;  //结点个数

struct Student
{
	int num;
	float score;
	struct Student *next;
};

struct Student *creat(void)   //建立链表的函数，初始化
{
	struct Student *head;
	struct Student *p1,*p2,*pt;
	n=0;
	printf("input student massage:\n");
	p1=(struct Student*)malloc(LEN);    //开辟动态链表空间
	p2=(struct Student*)malloc(LEN);
	scanf("%d,%f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n++;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(LEN);
		scanf("%d,%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	pt=head;
    printf("\nstudent massage:");
	while(pt!=NULL)
    {
       printf("\nnum:%d\nscore:%4.2f\n",pt->num,pt->score);   //依次打印学生信息
       pt=pt->next;
    }
    printf("------------------------------");
	return(head);   //head为返回首项，p2为返回最后一项
}

struct Student *find(struct Student *p,int number)    //按学号查找学生
{
	struct Student *head=NULL;
    printf("------------------------------");   
    head=p;

    while(p!=NULL)
    {
        if(p->num==number)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nerror! no such student.\n");
    }
    else
    {
        printf("\nfind student:\nnum:%d\nscore:%4.2f\n",p->num,p->score);
    }
    return (head);
}

struct Student *delate(struct Student *p,int number)       //删除一个学生信息，以学号为准
{
	struct Student *m=NULL,*head=NULL;
    int n=0;
    printf("------------------------------\ndelate: new student massage:");
    m=(struct Student*)malloc(LEN);    //不能放到循环内，干扰了head的赋值
    while(p!=NULL)
    {

        if(n==1)
        {
            head=m;
        }
        if(p->num==number)
        {
            p=p->next;
        }
        m->next=p;
        m=p;
        if(p==NULL)
        {
            break;
        }
        printf("\nnum:%d\nscore:%4.2f\n",m->num,m->score);
        p=p->next;
        n++;
    }
    return head;
}


struct Student *add(struct Student *p,int number,int adnum,float adsco)   //给指定学号前面加一个学生信息
{
    struct Student *head,*m=NULL,*pre,*pt;
    head=p;
    m=(struct Student*)malloc(LEN);
    m->num=adnum;
    m->score=adsco;
    if(p==NULL)
    {
        head=m;
        printf("\nnum:%d\nscore:%4.2f\n",m->num,m->score);
        return head;
    }
    while(p->num!=number&&p!=NULL)
    {
        pre=p;
        p=p->next;
    }
    if(p!=NULL)
    {
        if(p==head)
        {
            m->next=p;
            head=m;
        }
        else               //添加元素，把m添加到pre和p之间
        {
              m->next=p;
              pre->next=m;
        }
    }
    pt=head;
    while(pt!=NULL)
    {
        printf("\nnum:%d\nscore:%4.2f\n",pt->num,pt->score);
        pt=pt->next;
    }
    return head;

}

/*
struct Student *add(struct Student *p,int number,int adnum,float adsco)     //在输入学号前插入一个学生信息  (需要不断开辟新的内存，占用空间，不推荐使用)
{
    struct Student *head;
	struct Student *p1,*p2,*pt;	
	int n=0,k=0;
	p2=(struct Student*)malloc(LEN);
	head=NULL;	
	printf("------------------------------\nadd: new student massage:");
	if(p==NULL)
    {
        head->num=number;
        head->score=adsco;
        head->next=NULL;
    }
	while(p!=NULL)
	{
		if(p->num==number)
        {
            p1=(struct Student*)malloc(LEN);
            p1->num=adnum;
            p1->score=adsco;
            p2->next=p1;
            p2=p1;
            k=1;
            if(n==0)
            {
                head=p2;
                n=1;
            }
            if(p==NULL)
            {
                 break;
            }
        }
        p1=(struct Student*)malloc(LEN);
        p1->num=p->num;
        p1->score=p->score;
        p2->next=p1;
        p2=p1;
        p=p->next;
          if(n==0)
          {
               head=p2;
          }
        n++;
    }
	p2->next=NULL;
	if(k==0)
    {
        printf("\ninput error!\n");
    }
    else
        {
            pt=head;
            while(pt!=NULL)
            {
                printf("\nnum:%d\nscore:%4.2f\n",pt->num,pt->score);
                pt=pt->next;
            }
        }
	return(head);   //head为返回首项，p2为返回最后一项
}
*/

int main()
{
    struct Student *m;
    char choose;
    int fadnum,adnum,findnum,delnum;
    float adsco;
	m=creat();

	while(1)
    {
        //system("cls");    清屏幕
        fflush(stdin);      //清除输入的缓存，否则输入的回车会被误认为是输入
        printf("------------------------------\nselect the function you want to execute!\n");
        scanf("%c",&choose);    //不能用%s，否则结构体指针m的值会改变
        switch(choose)
        {
        case 'a':
         printf("input the student number who you want to add before: ");
         scanf("%d",&fadnum);
         printf("input the student number who you want to add: ");
         scanf("%d",&adnum);
         printf("input the student score who you want to add: ");
         scanf("%f",&adsco);

         m=add(m,fadnum,adnum,adsco);
         break;

        case 'f':
         printf("input the student number who you want to find: ");
         scanf("%d",&findnum);

         m=find(m,findnum);      //按学号查找学生
         break;

        case 'd':
         printf("input the student number who you want to delate:");
         scanf("%d",&delnum);

         m=delate(m,delnum);

         break;

        default:
         break;
        }

    }
    return 0;
}

//删除一个链表的正确方法
void DeleteList(struct Student *p)
{	
	struct Student *l,*tmp;
	l=p->next;
	p->next=NULL;
	while(l!=NULL)
	{
		tmp=l->next;
		free(l);
		l=tmp;
	}
}



