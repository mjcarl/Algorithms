#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<string>vec;
	string s;
	while (cin >> s)  //��Ϊ������ַ�������пո����ֹͣ�ˣ�������vector������Ч�������ո��������ֵ����⣬��ֱ̫6��
	{
		vec.push_back(s);
	}
	auto it = vec.end() - 1;
	cout << (*it).size() << endl;

	return 0;
}

/*
// C++
//��Щͬѧ�Ĵ�û���ǵ�ĩβ�пո�����������ĩβ�пո�Ķ����Ϊ0�ˡ�
//��hello world     ����Ȼ���5.
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s)){
		int n=0,flag=1;
		for(int i=s.length()-1;i>=0;--i){  //���ż���
			if(flag && s[i]==' '){  //���ĩβ�пո������ĩβ�ո�
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