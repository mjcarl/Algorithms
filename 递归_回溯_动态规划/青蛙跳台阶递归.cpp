#include<iostream>
#include<algorithm>

using namespace std;

int step(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return step(n - 1) + step(n - 2);
}




int main()
{
	int len;
	cout << "���뾮����ȣ� ";
	cin >> len;
	int methods;
	methods = step(len);
	cout << "methods= " << methods << endl;
	return 0;
}



//int fib(int n)   //쳲���������
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}