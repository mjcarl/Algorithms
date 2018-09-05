#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long >  vec;

int findIndex(long long value)
{

    long long right = vec.size()-1;
    long long left =0;
    long long mid =left+((right-left)>>2);
    while(left!=right)
    {
        mid =left+((right-left)>>2);
        if(vec[mid]==value)
        {
            return mid;
        }
        else if( vec[mid]>value )
        {

            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
  return left;
}

int main(){
    long long  n;
    while(cin >> n)
    {
        vec.clear();
        int value;
        long long sum=0;
        for(int i = 0; i < n; i++)
        {
            cin>>value;
            sum=sum+value;
            vec.push_back(sum);
        }
        long long  m;
        cin>>m;
         for(int i = 0; i < m; i++)
        {
            cin>>value;
             cout<<findIndex(value)+1<<endl;
        }
    }
    return 0;
}
