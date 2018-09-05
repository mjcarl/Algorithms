#include<bits/stdc++.h>
using namespace std;

int main()
{
	char c[10];
	int p, q;
	vector<int>vec(8,0);
	while (1)
	{
		cin >> c;
		char *e;
		const char* delim = ",";   // while (cin >> l >> ch >> r&&l != -1 && r != -1)
		e = strtok(c, delim);
		p = atoi(e);  //×Ö·û´®×ªÊý×Ö
		e = strtok(NULL, delim);
		q = atoi(e);
		//cout << p << " " << q << endl;
		if (p == -1 && q == -1)
			break;
		else
		{
			for (; p < q; p++)
			{
				vec[p - 12]++;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		cout << "[" << i + 12 << "," << i + 13 << "):" << vec[i] << endl;
	}

	return 0;
}