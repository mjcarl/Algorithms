#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
5 3
4 2 1 10 5
apple
orange
mango

7 19   min = 7, max = 19
*/
int main()
{

	int m, n, num;
	while (cin >> m >> n)   //m个标签  n个购物清单
	{
		vector<int> v;
		for (int i = 0; i<m; ++i)
		{
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		map<string, int> ms;   //会写！！  *********************

		for (int i = 0; i<n; ++i)
		{
			string s;
			cin >> s;
			ms[s]++;   //会用！！  *******************
		}

		int max = 0;
		int min = 0;

		vector<int> num;
		for (map<string, int>::iterator mit = ms.begin(); mit != ms.end(); ++mit)  //**********************
		{
			num.push_back(mit->second);  //统计个数，单独放到数组里
		}

		sort(num.begin(), num.end());   //从小到大

		int x = num.size();
		int y = v.size();

		for (int i = 0; i < x; i++)
		{
			min += v[i] * num[x-i-1];
			max += v[y-i-1] * num[x - i - 1];
		}
		cout << min << " " << max << endl;
	}
	return 0;
}
