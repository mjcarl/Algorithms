#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//十进制数123表达为16进制时只包含两位数7、11（B），用八进制表示时为三位数1、7、3。按不同进制表达时，各个位数的和也不同，
//如上述例子中十六进制和八进制中各位数的和分别是18和11。
//小B感兴趣的是，一个数A如果按2到A - 1进制表达时，各个位数之和的均值是多少？
int maxdivisor(int a, int b);
int main()
{
	int m; 
	int sum = 0, tmp;
	while (cin >> m)
	{
		int s = m;
		for (int i = 2; i < s; i++)
		{
			m = s;
			tmp = m % i;			
			while (m > 0)
			{
				sum += tmp;
				m = m / i;
				tmp = m % i;
			}
		}
		int d = maxdivisor(sum,s-2);
		cout << sum/d << "/" << (s - 2)/d << endl;   //不能直接输出，要求两个数的最大公约数，然后化简！
		sum = 0;
	}
	return 0;
}
int maxdivisor(int a, int b)   //****求最大公约数  a>b
{
	int d;
	while ((a % b) != 0)
	{
		d = a%b;
		a = b;
		b = d;
	}
	
	return b; 
}
