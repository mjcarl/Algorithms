#include<iostream>
#include<string>
using namespace std;

string s;
int N;

void Permutation(string::iterator it)    //  abc=> abc,acb,bac,bca,cab,cba
{
	if(it == s.end())
	{
		cout<<"final == "<<s<<endl;
	}
	else   //记着加else
	{
		for(string::iterator itmp = it;itmp!=s.end();++itmp)
		{
			char c;
			c = *itmp;
			*itmp = *it;
			*it = c;
			Permutation(it+1);   //注意是it不是itmp   +1不是++
			c = *itmp;
			*itmp = *it;
			*it = c;
		}
	}
}

int main()
{
	cin>>s;
	cout<<"========"<<endl;
	N = s.size();
	if(N==0)
		return 0;
	else
	{
		string::iterator it = s.begin();
		Permutation(it);
	}
	return 0;
}
