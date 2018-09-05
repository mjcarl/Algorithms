#include<bits/stdc++.h>
using namespace std;

const int inf=99999;
const int maxnum=10;
int dist[maxnum]={0}; //��ʾ��ǰԴ��v��ĳ�������С����
int pre[maxnum]={0};

int edg[maxnum][maxnum]={0};  //�ڽӾ���

void Dijkstra(int v0)
{
    bool s[maxnum+1];  //�ж��Ƿ��Ѿ����뵽����S��
    int n=maxnum,i,j;
    for(i=1;i<=n;i++)  //��ʼ��
    {
        dist[i]=edg[v0][i];  //�ڽӾ��󣬷�Ϊ0��x��inf
        s[i]=false;
        if(dist[i]==inf)
            pre[i]=-1;
        else
            pre[i]=v0;
    }
    dist[v0]=0;
    s[v0]=true;
    for(i=2;i<=n;i++)  //��Դ�����ÿһ���㣬ÿѭ��һ�ξ���ˢ��һ��״̬��
    {
        int mindist = inf;
        int best =v0;
        for(j=1;j<=n;j++)  //�ҵ���С����
        {
            if(s[j]==0 && dist[j]<mindist)
            {
                best = j;
                mindist = dist[j];
            }
        }
        s[best]=true;  //ѡ����ε�������ѽڵ�
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
