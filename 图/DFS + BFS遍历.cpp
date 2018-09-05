#include<bits/stdc++.h>
using namespace std;

int countnum=0;
int points,edgs;
int p1,p2;
int edg[10][10]; //边的度
int inf=999999;
int flag[10];  //访问的标志位

void bfs(int cur)  //只能用队列非递归实现，类似于树的层序遍历
{
    queue<int>q;
    flag[cur]=1;
    q.push(cur);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        cout<<tmp<<" ";
        for(int i=1;i<=points;i++)
        {
            if(edg[tmp][i]==1 && flag[i]==0)
            {
                q.push(i);
                flag[i]=1;
            }
        }
    }
}

void dfs(int cur)  // dfs递归
{
    cout<<cur<<" ";
    countnum++;
    if(countnum==points)  //个数到了，返回
        return;
    for(int i=1;i<=points;i++)
    {
        if(edg[cur][i]==1 && flag[i]==0)  //遍历存在边的关系 & 未被访问过的
        {
            flag[i]=1;
            dfs(i);
        }
    }
    return;
}

void dfs2(int cur)  //dfs的非递归  栈实现
{
    stack<int>s;  int i=0;
    flag[cur]=1;
    s.push(cur);
    while(!s.empyt())
    {
        int tmp=s.top();
        for(i=1;i<=points;i++)
        {
            if(edg[tmp][i]==1 && flag[i]==0)
            {
                flag[i]=1;
                s.push(i);
                cout<<i<<" ";
                break;
            }
        }
        if(i==points)  //如果前面遍历了发现与tmp相邻的节点都访问过了，则把tmp从栈里弹出
            s.pop();
    }
}

int main()
{
    int i,j;
    cin>>points>>edgs;
    for(i=1;i<=points;i++)
    {
        for(j=1;j<=points;j++)
        {
            if(i==j)
                edg[i][j]=0;
            else
                edg[i][j]=inf;  //先都初始化
        }
    }
    for(i=1;i<=edgs;i++)
    {
        cin>>p1>>p2;
        edg[p1][p2]=1;
        edg[p2][p1]=1;
    }
    for(i=1;i<=points;i++)  //dfs 每一个节点
    {
        for(j=1;j<=points;j++)
            flag[j]=0;  //dfs前先清空flag[]
        flag[i]=1;
        dfs(i);
        countnum=0;
        cout<<endl;
    }
    for(i=1;i<=points;i++)  //bfs  每一个节点
    {
        for(j=1;j<=points;j++)
            flag[j]=0;  //dfs前先清空flag[]
        bfs(i);
    }
}
