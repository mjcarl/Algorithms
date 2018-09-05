#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i;
	float tmp, sum, dou;
	vector<int>vec(n);
	for (i = 0; i<n; i++)
	{
		cin >> vec[i];
	}
	for (i = 0; i<n; i++)
	{
		sum = 0;
		if (vec[i] <= 5000)
			cout << sum << endl;
		else
		{
			tmp = vec[i] - 5000;
			if (tmp <= 3000)
			{
				sum = tmp*0.03;
				dou = sum - (int)sum;
				if (dou >= 0.5)
					sum++;
				cout << (int)sum << endl;
			}
			else
			{
				tmp = tmp - 3000;
				sum = sum + 3000 * 0.03;
				if (tmp <= 9000)
				{
					sum = sum + tmp*0.1;
					dou = sum - (int)sum;
					if (dou >= 0.5)
						sum++;
					cout << (int)sum << endl;
				}
				else
				{
					tmp = tmp - 9000;
					sum = sum + 9000 * 0.1;
					if (tmp <= 13000)
					{
						sum = sum + tmp*0.2;
						dou = sum - (int)sum;
						if (dou >= 0.5)
							sum++;
						cout << (int)sum << endl;
					}
					else
					{
						tmp = tmp - 13000;
						sum = sum + 13000 * 0.2;
						if (tmp <= 10000)
						{
							sum = sum + tmp*0.25;
							dou = sum - (int)sum;
							if (dou >= 0.5)
								sum++;
							cout << (int)sum << endl;
						}
						else
						{
							tmp = tmp - 10000;
							sum = sum + 10000 * 0.25;
							if (tmp <= 20000)
							{
								sum = sum + tmp*0.3;
								dou = sum - (int)sum;
								if (dou >= 0.5)
									sum++;
								cout << (int)sum << endl;
							}
							else
							{
								tmp = tmp - 20000;
								sum = sum + 20000 * 0.3;
								if (tmp <= 25000)
								{
									sum = sum + tmp*0.35;
									dou = sum - (int)sum;
									if (dou >= 0.5)
										sum++;
									cout << (int)sum << endl;
								}
								else
								{
									tmp = tmp - 25000;
									sum = sum + 25000 * 0.35;
									sum = sum + tmp*0.45;
									dou = sum - (int)sum;
									if (dou >= 0.5)
										sum++;
									cout << (int)sum << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}