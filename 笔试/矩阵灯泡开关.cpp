#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int i, j, tmp;
	bool yy = true;

	vector<vector<int>> array(m);
	for (i = 0; i < array.size(); i++)
		array[i].resize(n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> tmp;
			array[i][j] = tmp;
		}
	}
	for (i = 0; i < m && yy == true; i++)
	{
		for (j = 0; j < n && yy == true; j++)
		{
			if (array[i][j] == 0)
			{
				int x = i, y = j;
				for (x = 0; x < m; x++)
				{
					if (array[x][j] == 1)
					{
						yy = false;
						break;
					}
						
				}
				for (y = 0; y < n && yy == true; y++)
				{
					if (array[i][y] == 1)
					{
						yy = false;
						break;
					}
				}
			}
		}
	}
	if (yy == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
















