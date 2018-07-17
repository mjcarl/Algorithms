#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//题目描述：ABCDE五个人传球，由A开始第一次传球，经5次传球后传回到A的手上。
//其中A与B不会相互传球，C只会传给D，E不会传给C，共有多少种传法？

vector<char> enumpass = { 'A' ,'B' ,'C' ,'D' ,'E' };
vector<char> res; 
int i, sum=0; 
char lastchar = 'F';
void nums(char x)
{	
	if (res.size() == 6 )
	{
		if (x == 'A' && lastchar != 'B'&& lastchar != 'C')
		{
			vector<char>::iterator it = res.begin();
			while (it != res.end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;	
			sum++;
		}
		res.pop_back();
		return;
	}
	else if ((x == 'A' && lastchar == 'B') || (x == 'B' && lastchar == 'A') || (x == 'C' && lastchar == 'E') || (x != 'D' && lastchar == 'C'))
	{
		res.pop_back();
		return;
	}
	else
	{
		vector<char>::iterator it = enumpass.begin();
		for (; it != enumpass.end(); it++)
		{
			if(*it != x)
			{
				res.push_back(*it);
				lastchar = x;
				nums(*it);
			}			
		}
		res.pop_back();
		return;
	}
}
int main()
{
	res.push_back('A');
	lastchar = 'F';
	nums('A');
	cout << sum << endl;
	return 1;
}


