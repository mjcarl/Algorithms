#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<string>s(m);
	int i, j, k;
	long zong[2 ^ 32] = { 0 };  //总的长度答案
	long every[2 ^ 16][2] = { 0 };  //每个人的长度答案
	int num = 0;//每组的个数
	int max = 0;
	for (i = 0; i < m; i++)
	{
		cin >> s[i];
		num = 0;

		auto it = s[i].begin();
		int tmp = 0;
		bool qian = true;
		while (it != s[i].end())
		{
			if (*it >= '0'&&*it <= '9')
			{
				tmp = tmp * 10 + (*it - '0');
			}
			if (*it == ',')
			{
				if (qian)
					every[num][0] = tmp;
				else
					every[num][1] = tmp;
				qian = !qian;
				if (tmp > max)
					max = tmp;
				//cout << tmp << " ===" << endl;
				tmp = 0;
			}
			if (*it == ';')
			{
				if (qian)
					every[num][0] = tmp;
				else
					every[num][1] = tmp;
				//cout << tmp << " ===" << endl;
				if (tmp > max)
					max = tmp;
				qian = !qian;
				tmp = 0;
				num++;
			}
			it++;
		}
		every[num][1] = tmp;
		//cout << tmp << " ===" << endl;
		if (tmp > max)
			max = tmp;
		int x, y;
		for (j = 0; j <= num; j++)
		{
			x = every[j][0];
			y = every[j][1];
			for (k = x; k <= y; k++)
			{
				if (zong[k] == 0)
				{
					zong[k] = 1;
					//cout << "k ==  " << k << endl;
				}
					
			}
		}
	}
	int b, e;
	bool zero = true;
	//cout << "max=====  " << max << endl;
	string res = "";
	for (i = 0; i <= max+1; i++)
	{
		if (zong[i] == 1 && zero == true)
		{
			b = i;
			zero = false;
		}
		if (zong[i] == 0 && zero == false)
		{
			e = i-1;
			zero = true;
			//cout << "b= " << b << " e=  " << e << endl;
			res = res + to_string(b) + ',' + to_string(e) + ';';
		}
	}
	res.erase(res.end() - 1);
	cout << res << endl;

	return 0;
}