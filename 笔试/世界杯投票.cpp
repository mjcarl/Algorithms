#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;   //N个球星，M个投票人
	int i, j;
	string s;
	vector<vector<char>> arr(M);
	for (i = 0; i < arr.size(); i++)
		arr[i].resize(N);

	for (i = 0; i < M; i++)
	{
		cin >> s;
		for (j = 0; j < N; j++)
		{
			arr[i][j] = s[j];
		}
	}
	vector<vector<int>> res(N);
	for (i = 0; i < res.size(); i++)
		res[i].resize(26);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 26; j++)
		{
			res[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			char c = 'a'; int k = 0;	
			while (c != arr[j][i])
			{
				c += 1;
				k++;
			}
			res[i][k]++;
		}
	}

	vector<int> ms;
	for (i = 0; i < N; i++)
		ms.push_back(i);

	int k = 0, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = i+1; j < N; j++)
		{
			k = 0;
			while (k < 26 )
			{
				if (res[i][k] > res[j][k])
					break;
				if (res[i][k] < res[j][k])
				{
					tmp = ms[i];
					ms[i] = ms[j];
					ms[j] = tmp;
					break;
				}
				k++;
			}
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (res[ms[0]][i] != res[ms[1]][i])
		{
			break;
		}
	}
	if (i == 26)
		cout << -1 << endl;
	else
		cout << ms[0] << endl;

	return 0;
}