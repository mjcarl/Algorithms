#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//-----------------------�����ڱ�������ʳ����   abc=> a,b,c,ab,ac,bc,abc
string s;
string res;
int N;
bool x[100]={0};

void printString(string)
{

}
void backtrace(string res,int deep)
{
	if(deep)
		cout<<res<<endl;
	if(deep == N)
		return;
	
	for(int i=deep;i<N;i++)   //ע��i��deep��ʼ
	{
		if(x[i] == false)
		{
			x[i] = true;
			res += s[i];
			backtrace(res,i+1);   //ע�������i+1������deep+1�� �˴���ͬ��ȫ����
			res.pop_back();
			x[i] = false;
			//cout<<"pop == "<<res<<endl;
		}
		
	}
}

int main()
{
	cin>>s;
	N = s.size();
	res.clear();
	sort(s.begin(),s.end());
	backtrace(res,0);
	return 0;
}