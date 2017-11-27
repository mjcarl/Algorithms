#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<time.h>


#define oneway_MAXVEX 1000   //�������
#define INF 1000000  //���޷���
#define M 6
//#define Probability 10   //10/1000=0.01�ı�����

//�ͼ�case��M=61  ����15�Σ��м�case��M=31   ����

int numVertex,numEdge,numXiaofei;
int costFuwuqi,numFuwuqi=0;
int sumXiaofei=0;
int minCost=0,maxFlow=0;
int route_num=0;
int fun_time=0;
int Probability=300;
int location[999];
int fang[999]={0};   //�Ƿ�ŷ�����
int liuliang=0;
long start_time=0,end_time=0;
double second;

typedef struct Vertex   //�ڽӱ�洢
{
    int name;
    int cap;  //����
	int cost;
    int flow;   //��ʵ����
    int xiaofei;
    int fuwuqi;
    struct Vertex *next;
}vertex;
vertex vex[1000];   //��Ž��ṹ������飻

typedef struct Vertex2   //�ڽӱ�洢
{
    int name;
    int cap;
    int cost;
    int flow;
    int xiaofei;
    int fuwuqi;
	float ave;    //������
    struct Vertex2 *next;
}vertex2;
vertex2 newvex[1000];   //��Ž��ṹ������飻


int mymin(int x,int y)
{
    return x>y?y:x;
}

//-------------------------------------------------------
typedef struct QNode    //���еĸ��ֻ�������
{
    int data;
    struct QNode *next;
}QNode;

struct Node
{
    QNode *front_my;
    QNode *rear;
};

void initQNode(struct Node *q)
{
    q->front_my=(struct QNode *)malloc(sizeof(struct QNode));
    q->rear=(struct QNode *)malloc(sizeof(struct QNode));

    q->front_my=q->rear;
    q->front_my->next=NULL;
}

void push(struct Node *q,int x)   //Ԫ�����
{
    QNode* p=(struct QNode *)malloc(sizeof(struct QNode));
    p->data=x;  
    q->rear->next=p;
    q->rear=p;
    p->next=NULL;

}

int front_my(struct Node *q)  //ȡ������Ԫ��
{
    int e=0;
    QNode *p;
    p=q->front_my->next;
    e=p->data;
    q->front_my->next=p->next;
    if(q->rear==p)
        q->rear=q->front_my;
	free(p);
	p=NULL;
    return e;
}

int my_empty(struct Node *q)  //�ӿ�Ϊ0
{
    return !(q->front_my==q->rear);
}
//---------------------------------------------------
typedef struct Stack   //ջ�Ľṹ�壬��������·��
{
    int Vex[1000];
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
//-------------------------------------------------------
//-------------------------------------------------------

void print()   //��ӡ�ڽӱ����ÿ�ע�͵�
{
	int i;
	vertex *p=NULL;
	for(i=0;i<=numVertex+1;i++)
	//for(i=0;i<numVertex;i++)
	{
		printf("ͷ��%d fuwuqi=%d xiaofei=%d",vex[i].name,vex[i].fuwuqi,vex[i].xiaofei);
		p = &vex[i];
		while(p->next!=NULL)
		{
			printf("--->%d cap=%d cost=%d",p->next->name,p->next->cap,p->next->cost);
			p=p->next;
		}
		printf("\n");
	}
}

int init()
{
    int i,ii=0;
    int a,b,c,d,xf,w,mc;
   // char reg[20];

    struct Vertex *v1,*e1,*x1,*y1;
	struct Vertex2 *v2,*e2;
	FILE *fp=fopen("test.txt","r");
    sumXiaofei=0;
	if(!fp)
	{
		printf("can't open file!\n");
		return 0;
	}
	else
	{

        fscanf(fp,"%d %d %d",&numVertex,&numEdge,&numXiaofei);
        printf("%d %d %d\n",numVertex,numEdge,numXiaofei);
        fgetc(fp);

        for(i=0;i<=numVertex+1;i++)   //��ʼ��ͷ�������
        {
            vex[i].name=i-1;
            vex[i].cap=0;
            vex[i].cost=0;
            vex[i].flow=0;
            vex[i].fuwuqi=0;
            vex[i].xiaofei=-1;  //���ӵ����ѽ��name��û��Ϊ-1
            vex[i].next=NULL;

			newvex[i].name=i;
            newvex[i].cap=0;
            newvex[i].cost=0;
            newvex[i].flow=0;
            newvex[i].fuwuqi=0;
            newvex[i].xiaofei=-1;
			newvex[i].ave=0;
            newvex[i].next=NULL;
        }
        vex[0].name=-1;  //��Դ������
        vex[numVertex+1].name=-2;   //���������

        fgetc(fp);
		fscanf(fp,"%d",&costFuwuqi);
		printf("\ncostFuwuqi=%d\n\n",costFuwuqi);
		fgetc(fp);
		fgetc(fp);

        for(i=0;i<numEdge;i++)    //��ȡÿ�����������Ϣ
		{
			fscanf(fp,"%d %d %d %d",&a,&b,&c,&d);

			vex[a+1].name=a;      // a->b  vex[1].name=0
			v1 = (vertex *)malloc(sizeof(vertex));
            v1->name=b;
            v1->cap=c;
			v1->cost=d;
            v1->flow=0;
            v1->xiaofei=-1;
            v1->fuwuqi=0;
            v1->next=vex[a+1].next;
            vex[a+1].next=v1;

            vex[b+1].name=b;
            e1 = (vertex *)malloc(sizeof(vertex));
            e1->name=a;
            e1->cap=c;
			e1->cost=d;
            e1->flow=0;
            e1->xiaofei=-1;
            e1->fuwuqi=0;
            e1->next=vex[b+1].next;
            vex[b+1].next=e1;

			newvex[a].name=a;      // a->b   vex[0].name=0
			v2 = (vertex2 *)malloc(sizeof(vertex2));
            v2->name=b;
            v2->cap=c;
			v2->cost=d;
            v2->flow=0;
            v2->xiaofei=-1;
            v2->fuwuqi=0;
			v2->ave=0;
            v2->next=newvex[a].next;
            newvex[a].next=v2;

            newvex[b].name=b;
            e2 = (vertex2 *)malloc(sizeof(vertex2));
            e2->name=a;
            e2->cap=c;
			e2->cost=d;
            e2->flow=0;
            e2->xiaofei=-1;
            e2->fuwuqi=0;
			e2->ave=0;
            e2->next=newvex[b].next;
            newvex[b].next=e2;

			fgetc(fp);
		}
		fgetc(fp);
		printf("\n");

        for(i=0;i<numXiaofei;i++)    //��ȡÿ�����ѽ����Ϣ
		{
			fscanf(fp,"%d %d %d",&xf,&w,&mc);
			sumXiaofei=sumXiaofei+mc;
			vex[w+1].xiaofei=xf;

			newvex[w].xiaofei=xf;
			newvex[w].cap=mc;    //�����ѽ�����С����ŵ�cap�û���ӵ�Ϊ0
			x1 = ( vertex *)malloc(sizeof(vertex));
            y1 = ( vertex *)malloc(sizeof(vertex));

            x1->name=-2;    //���ӵ������
            x1->cap=mc;
            x1->cost=1;   //ע�����minCost��������
            x1->flow=0;
            x1->fuwuqi=0;
            x1->xiaofei=-1;
            x1->next=vex[w+1].next;
            vex[w+1].next=x1;

            y1->name=w;  //����㷴���
            y1->cap=0;
            y1->cost=0;
            y1->flow=0;
            y1->fuwuqi=0;
            y1->xiaofei=-1;
            y1->next=vex[numVertex+1].next;
            vex[numVertex+1].next=y1;

            fgetc(fp);
		}
	}
	fclose(fp);
	return 1;
}

void SPFA( )
{
    char result[10000];
    int a[oneway_MAXVEX];   //һ��·�ɸĽ���

    int d[oneway_MAXVEX];  //��ŵ��˽�����С����
    int inq[oneway_MAXVEX];  //0 1��ʾ����Ƿ��ڶ�����
    int p[oneway_MAXVEX];   //��Ÿ��׽����
    struct Node *q=(struct Node *)malloc(sizeof(struct Node));
    stack s;
	route_num=0;
    minCost=0;
    maxFlow=0;

    while(1)    //����ѭ����ֱ������
    {
        int i,uu,v;
        struct Vertex *x=(struct Vertex *)malloc(sizeof(struct Vertex));
        struct Vertex *y=(struct Vertex *)malloc(sizeof(struct Vertex));
        s=createstack();   //��·����
        initQNode(q);
        for(i=0;i<=numVertex+1;i++)
        {
            d[i]=INF;  //������ı�ţ���ʼ���붼���޴�
            inq[i]=0;  //������ı�ţ�û��Ԫ�����
        }
        d[0]=0;  //Դ����С
        a[0]=INF;
        push(q,0);

        while(my_empty(q)!=0)  //����ӷǿ�
        {
            int u=front_my(q);  //����Ԫ�ظ�u

            inq[u]=0;  //�ñ�־λΪ0
            x=&vex[u];
            x=x->next;
            while(x!=NULL)
            {
                if(x->name==-1)
					v=0;
				else if(x->name==-2)
					v=numVertex+1;
				else
					v=(x->name)+1;
                if(x->cap>x->flow && d[v]>d[u]+x->cost)  //��������ʣ�� �� ���Ѹ���   =???????
                {
                    d[v]=d[u]+x->cost;
                    p[v]=u;  //v�ĸ��׽��Ϊu
                    a[v]=mymin(a[u],(x->cap)-(x->flow));   //ȡ·���ϵ��������
                    if(inq[v]==0)
                    {
                        inq[v]=1;
                        push(q,v);
                    }
                }
                x=x->next;
            }
        }

        if(d[numVertex+1]==INF)
            break;
        maxFlow=maxFlow+a[numVertex+1];
        minCost=minCost+d[numVertex+1]*a[numVertex+1];
        uu=numVertex+1;
        i=p[uu];
        while(uu!=0)  //�������ı��Ϊ0
        {
            x=&vex[p[uu]];
            y=&vex[uu];
            while(x->name!=vex[uu].name)
                x=x->next;
            x->flow=x->flow+a[numVertex+1];
            while(y->name!=vex[p[uu]].name)
			{
                y=y->next;
			}
            y->flow=y->flow-a[numVertex+1];
            uu=p[uu];

        }
        /*while(i!=0)
        {
            push_s(s,i);
            i=p[i];
        }
        while(s->top!=-1)
        {
            printf("%d ",vex[s->Vex[s->top]].name);
            if(s->top==0)
            {
                printf("%d ",vex[s->Vex[0]].xiaofei);
            }
            s->top--;
        }
        printf("��·����=%d\n",a[numVertex+1]);
        route_num++;*/
    }
	//DFS�����·��
	DFS();
	printf("\nnumFuuwqi=%d\n",numFuwuqi);
	printf("route_num=%d \n",route_num);
	printf("maxFlow=%d  sumXiaofei=%d\n", maxFlow,sumXiaofei);
	printf("minF=%d\n",minCost-maxFlow*2+costFuwuqi*numFuwuqi);
}

int DFS(int x,int minflow)   //x�Ǳ��
{
	vertex *p;
	
	if(x==numVertex+1)
		return minflow;
	used[x]=1;
	p=&vex[x];
	p=p->next;
	while(p!=NULL)
	{
		if(used[p->name+1]==0 && p->flow>0)
		{
			d=DFS(p->name+1,p->flow);
			if(d>0)
			{
				p->flow=p->flow-d;

	}

}



void fuwuqi(int * fang)   //����case��ȫ�ַŷ�����
{
	struct Vertex *k,*h,*p;
	int j;
	numFuwuqi=0;
	vex[0].next=NULL;
	p=&vex[0];
	p=p->next;
	while(p!=NULL)
	{
		free(p);
		p=p->next;
	}
	for(j=1;j<=numVertex;j++)   //�ӵ�һ�п�ʼ��
	{
		vex[j].fuwuqi=fang[j-1];   //���÷�����
		if(vex[j].fuwuqi==1)
		{
			numFuwuqi++;
			k = (vertex *)malloc(sizeof(vertex));   //��Դ�㵽������
            h = (vertex *)malloc(sizeof(vertex));
            k->name=vex[j].name;
            k->cap=INF;
            k->cost=1;
            k->flow=0;
            k->fuwuqi=0;
            k->xiaofei=-1;

            k->next=vex[0].next;
            vex[0].next=k;

            h->name=-1;  //��Դ�㷴���
            h->cap=0;
            h->cost=0;
            h->flow=0;
            h->fuwuqi=0;
            h->xiaofei=-1;

            h->next=vex[j].next;
            vex[j].next=h;
			}
		}
}

void main()
{
	init();
	print();
	fang[0]=1;
	fuwuqi(fang);
	SPFA();
}
