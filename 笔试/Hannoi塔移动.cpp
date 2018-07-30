#include <iostream>

using namespace std;

void Hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		cout << "  move from " << x << " to " << z << endl;
	else
	{
		Hanoi(n - 1, x, z, y);   //��n-1������Ų����
		Hanoi(1, x, y, z);      //�ѵ��µĴ���Ų����
		Hanoi(n - 1, y, x, z);   //��n-1������Ų����
	}
}

int main()
{
	int n;
	cout << "���뺺ŵ����Բ������ ";
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}