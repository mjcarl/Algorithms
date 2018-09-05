#include<bits/stdc++.h>
using namespace std;

const int inf=99999;
const int maxnum=10;
int dist[maxnum]={0}; //表示当前源点v到某个点的最小距离
int pre[maxnum]={0};

int edg[maxnum][maxnum]={0};  //邻接矩阵

void Dijkstra(int v0)
{
    bool s[maxnum+1];  //判断是否已经存入到集合S里
    int n=maxnum,i,j;
    for(i=1;i<=n;i++)  //初始化
    {
        dist[i]=edg[v0][i];  //邻接矩阵，分为0、x、inf
        s[i]=false;
        if(dist[i]==inf)
            pre[i]=-1;
        else
            pre[i]=v0;
    }
    dist[v0]=0;
    s[v0]=true;
    for(i=2;i<=n;i++)  //除源点外的每一个点，每循环一次就是刷新一次状态表
    {
        int mindist = inf;
        int best =v0;
        for(j=1;j<=n;j++)  //找到最小距离
        {
            if(s[j]==0 && dist[j]<mindist)
            {
                best = j;
                mindist = dist[j];
            }
        }
        s[best]=true;  //选出这次迭代的最佳节点
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && edg[best][j]<inf)
            {
                if(dist[best]+edg[best][j]<dist[j])
                {
                    dist[j]=dist[best]+edg[best][j];
                    pre[j]=best;
                }
            }
        }
    }
}
