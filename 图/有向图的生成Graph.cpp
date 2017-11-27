#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<iostream>



//简单的有向图图的邻接矩阵，按行输入
#define MAXVEX 100
#define INFINITY 65535

typedef char Vertex;
typedef int Edge;



typedef struct Graph
{
	Vertex vexs[MAXVEX];
	Edge arc[MAXVEX][MAXVEX];
	int numVertex,numEdge;
}*Gra;

Gra CreateGraph()     //生成图信息
{
	int i,j;
	Gra g=(Gra)malloc(sizeof(Graph));
	if(!g)
		exit(-1);

	printf("input the number of Vertexs :\n");
	scanf_s("%d,%d",&g->numVertex);

	printf("input the name of Vertex:\n");
	for(i=0;i<g->numVertex;i++)
	{
		g->vexs[i]=getchar();
		while(g->vexs[i]=='\n')
			g->vexs[i]=getchar();
	}

	printf("input the weight of edges:\n");
	for(i=0;i<g->numVertex;i++)
		for(j=0;j<g->numVertex;j++)
		{
			scanf_s("%d",&g->arc[i][j]);
		}
	return g;
}

Gra printGraph(Gra g)   //打印矩阵
{
	int i,j;
	

	printf("   ");
	for(i=0;i<g->numVertex;i++)
	{		
		printf("%c ",g->vexs[i]);		
	}
	printf("\n");
	for(i=0;i<g->numVertex;i++)
	{
		printf("%c: ",g->vexs[i]);
		for(j=0;j<g->numVertex;j++)
		{
			printf("%d ",g->arc[i][j]);
		}
		printf("\n");
	}
	return g;
}

int main()
{
	Gra g;
	g=CreateGraph();
	printGraph(g);
	return 1;
}


//图的邻接表生成-------------------------------------------------


typedef struct vertex   //顶点
{
	Vertex name;    //顶点名称
	Edge *firstedge;    //边表头指针
}vertex,Adjlist[MAXVEX];

typedef struct edgenode  //边表结点
{
	int adj;   //存储对应结点的下标
	Edge weight;    //对应权重
	struct edgenode *next;
}edgenode;

typedef struct
{
	Adjlist adjlist;     //头结点数组
	int numVertex,numEdge;
}Graphlist;

int find(Graphlist *g,char c)
{
	for(int i=0;i<g->numVertex;i++)
	{
		if(c==g->adjlist[i].name)
			return i;
	}
}

void CreateGraph(Graphlist *g)
{
	int i,j,k;
	edgenode *e,*f;
	printf("input the number of vertexs and edges:\n");   //顶点数与边数
	scanf_s("%d %d",&g->numVertex,&g->numEdge);
	printf("input the name of Vertex:\n");     //顶点名字
	for(i=0;i<g->numVertex;i++)
	{
		g->adjlist[i].name=getchar();
		while(g->adjlist[i].name=='\n')
			g->adjlist[i].name=getchar();
		g->adjlist[i].firstedge=NULL;//空指针
	}

	for(j=0;j<g->numEdge;j++)
	{
		e=(edgenode *)malloc(sizeof(edgenode));
		if(!e)
		{
			printf("errer malloc e!\n");
			exit(-1);
		}
		f=(edgenode *)malloc(sizeof(edgenode));
		if(!f)
		{
			printf("errer malloc f!\n");
			exit(-1);
		}
		printf("input the two edges' name:\n");    //相连的两边 m->n
		char p,q;
		int m,n;
		p=getchar();
		while(p=='\n')
			p=getchar();
		q=getchar();

		while(q=='\n')
			q=getchar();

		m=find(g,p);
		n=find(g,q);
		printf(" %d %d\n",m,n);
		printf("input the two edges' weight:\n");
		scanf_s("%d",&e->weight);

		//void *temppoint = (void *)g->adjlist[i].firstedge;
		//g->adjlist[m].firstedge = (Graphlist *)temppoint;
		e->adj=n;        //将n结点插入到顶点m的后面
		e->next=g->adjlist[m].firstedge;
		g->adjlist[m].firstedge=e;
        
		//f->adj=n;            //无向图时使用
		//f->next=g.adjlist[n].firstedge;
		//g.adjlist[n].firstedge=f;
	}
}

void printGraph(Graphlist *g)
{
	int i=0;
	printf("打印邻接表：");
	while(g->adjlist[i].firstedge!=NULL&&i<MAXVEX)
	{
		printf("\nVertex: %c  ",g->adjlist[i].name);
		edgenode *e=NULL;
		e=g->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("%d ",e->adj);
			e=e->next;
		}
		i++;
	}
}
	

		
void main()
{
	Graphlist *g;
	CreateGraph(g);
	printGraph(g);
}















































