#include <iostream>

using namespace std;

//int main()   //FFT FFT FFT
//{
//	int begin, end;
//	cin >> begin >> end;
//	int sum = 0;
//	string str;
//	int num = 0; int he = 0; int tmp = 0;
//	for (int i = 1; i < begin; i++)
//	{
//		tmp = i;
//		while (tmp)
//		{
//			he += (tmp % 10);
//			tmp = tmp / 10;
//		}
//	}
//	for (int k = begin; k <= end; k++)
//	{
//		tmp = k;
//		while (tmp)
//		{
//			he += (tmp % 10);
//			tmp = tmp / 10;
//		}
//		
//		if (he % 3 == 0)
//			sum++;
//	}
//	cout << sum << endl;
//	return 0;
//}


int main()
{
	long long l, r, num = 0;
	cin >> l >> r;
	for (; l <= r; l++)
	{
		long long s = l*(l + 1) / 2;
		if (!(s % 3)) num++;
	}
	cout << num << endl;
	return 0;
}