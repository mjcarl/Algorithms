#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int i, j, k;
	string tmp;
	bool ok = true;
	auto it = s.begin();

	for (i = 1; i <= s.size(); i++)  //i±íÊ¾¼ä¸ô
	{
		ok = true;
		//cout << "i=  " << i << endl;
		j = 0;
		while(j < s.size() && ok == true)
		{
			//cout << "jjjj=  " << j << endl;
			for (k = j; k < j+i&&k<s.size(); k++)
			{
				//cout << "s[k%i]= " << s[k%i] << "  s[k]= "<< s[k] <<endl;
				if (s[k%i] != s[k])
				{
					ok = false;
					break;
				}
			}
			j = j + i;
		}
		if (ok == true)
		{
			for (j = 0; j < i; j++)
			{
				cout << *it;
				it++;
			}
			cout << endl;
			break;
		}

	}
	return 0;
}