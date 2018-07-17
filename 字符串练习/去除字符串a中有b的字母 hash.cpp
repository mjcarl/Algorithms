#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	map<char,int> mp2;
	auto it = s2.begin();
	while(it != s2.end())
	{
		mp2[*it]++;
		it++;
	}
	int count=0;
	auto it1 = s1.begin();
	while(it1 != s1.end())
	{
		count = mp2[*it1];
		if(count > 0)
			s1.erase(it1);
		it1++;
	}
	cout<<s1<<endl;
	return 0;
}



//int main()
//{
//	string s;
//	cin>>s;
//	int i=0;
//	map<char,int> mp;   //ÓÃhash map´æ´¢¼ÆÊý
//	auto it = s.begin();
//	while(it != s.end())
//	{
//		mp[*it]++;
//		++it;
//	}
//	auto itmap = mp.begin();
//	while(itmap != mp.end())
//	{
//		if(itmap->second == 1)
//			break;
//		++itmap;
//	}
//	if(itmap != mp.end())
//		cout<<itmap->first<<endl;
//	else
//		cout<<"error"<<endl;
//
//	return 0;
//}