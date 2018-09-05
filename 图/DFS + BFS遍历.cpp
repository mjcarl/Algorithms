#include<bits/stdc++.h>
using namespace std;

int countnum=0;
int points,edgs;
int p1,p2;
int edg[10][10]; //�ߵĶ�
int inf=999999;
int flag[10];  //���ʵı�־λ

void bfs(int cur)  //ֻ���ö��зǵݹ�ʵ�֣����������Ĳ������
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

void dfs(int cur)  // dfs�ݹ�
{
    cout<<cur<<" ";
    countnum++;
    if(countnum==points)  //�������ˣ�����
        return;
    for(int i=1;i<=points;i++)
    {
        if(edg[cur][i]==1 && flag[i]==0)  //�������ڱߵĹ�ϵ & δ�����ʹ���
        {
            flag[i]=1;
            dfs(i);
        }
    }
    return;
}

void dfs2(int cur)  //dfs�ķǵݹ�  ջʵ��
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
        if(i==points)  //���ǰ������˷�����tmp���ڵĽڵ㶼���ʹ��ˣ����tmp��ջ�ﵯ��
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
                edg[i][j]=inf;  //�ȶ���ʼ��
        }
    }
    for(i=1;i<=edgs;i++)
    {
        cin>>p1>>p2;
        edg[p1][p2]=1;
        edg[p2][p1]=1;
    }
    for(i=1;i<=points;i++)  //dfs ÿһ���ڵ�
    {
        for(j=1;j<=points;j++)
            flag[j]=0;  //dfsǰ�����flag[]
        flag[i]=1;
        dfs(i);
        countnum=0;
        cout<<endl;
    }
    for(i=1;i<=points;i++)  //bfs  ÿһ���ڵ�
    {
        for(j=1;j<=points;j++)
            flag[j]=0;  //dfsǰ�����flag[]
        bfs(i);
    }
}
