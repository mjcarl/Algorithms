#include<iostream>
using namespace std;

void main()
{
	int base,exp;
	cin>>base>>exp;
	double pp(double base,int exp);
	int res = pp(base,exp);
	cout<<res<<endl;
}

double pp(double base,int exp)  //exp>=0
{
	if(exp==0)
		return 1;
	else if(exp==1)
		return base;

	double res = pp(base,exp>>1);
	res *= res;
	if(exp&0x1==1)
		res *= base;
	return res;
}
