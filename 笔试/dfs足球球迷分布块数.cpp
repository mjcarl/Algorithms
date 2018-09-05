#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;
bool  ask[1005][1005];
bool  vec[1005][1005];
int  cnt=0;
int geshu;
//int   max=0;
void dfs (int i,int j,int M,int N)
{
    if(i>=0 && i<M && j>=0 && j<N && vec[i][j]==true && ask[i][j]==false)
    {
        cnt++;
        ask[i][j]= true;
        dfs(i-1,j-1,M,N);
        dfs(i,j-1,M,N); dfs(i-1,j,M,N);
        dfs(i+1,j-1,M,N); dfs(i-1,j+1,M,N);
        dfs(i+1,j+1,M,N); dfs(i+1,j,M,N); dfs(i,j+1,M,N);

    }
}

int main(){
    //freopen("1.in","r",stdin);
    int M,N ;
    char dou;
    string strtemp;

    while(cin>>M>>dou>>N)
    {
        memset(vec,false,sizeof(vec));
        memset(ask,false,sizeof(ask));
        bool value;
        int i,j;
        for( i = 0; i < M; i++){
            for( j = 0; j < N-1; j++){
               cin>>value>>dou;
                vec[i][j]=value;
            }
            cin>>vec[i][N-1];
        }
        int p=0,q=0;
        for( i = 0; i < M; i++){
            for( j = 0; j < N; j++){
                if(vec[i][j]==true && ask[i][j]==false)
                {
                    dfs(i,j,M,N);
                    p++;
                    q=max(q,cnt);
                    cnt=0;
                }
            }
        }

        cout << p<<"," <<q<< endl;
    }
    return 0;
}
