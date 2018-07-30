#include <iostream>

using namespace std;

void Hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		cout << "  move from " << x << " to " << z << endl;
	else
	{
		Hanoi(n - 1, x, z, y);   //把n-1个从右挪到中
		Hanoi(1, x, y, z);      //把底下的从右挪到左
		Hanoi(n - 1, y, x, z);   //把n-1个从中挪到右
	}
}

int main()
{
	int n;
	cout << "输入汉诺塔的圆盘数： ";
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}