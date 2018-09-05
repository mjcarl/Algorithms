#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<string>vec;
	string s;
	while (cin >> s)  //因为输入的字符串如果有空格就算停止了，所以用vector可以有效避免多个空格连续出现的问题，简直太6了
	{
		vec.push_back(s);
	}
	auto it = vec.end() - 1;
	cout << (*it).size() << endl;

	return 0;
}

/*
// C++
//有些同学的答案没考虑到末尾有空格的情况，对于末尾有空格的都输出为0了。
//“hello world     ”依然输出5.
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s)){
		int n=0,flag=1;
		for(int i=s.length()-1;i>=0;--i){  //倒着计算
			if(flag && s[i]==' '){  //如果末尾有空格，先清除末尾空格
				continue;
			}
			else if(s[i]!=' '){
				flag = 0;
				++n;
			}
			else{
				break;
			}
		}
		cout << n << endl;
	}
	return 0;
}
*/