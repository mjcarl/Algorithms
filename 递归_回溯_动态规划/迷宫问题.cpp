#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&vec, vector<vector<int>>&zouguo, vector<pair<int, int>>&visit, int row, int col, int m, int n)
{
	if (row<0 || row >= m || col<0 || col >= n || vec[row][col]==1)
		return;
	if (row == m-1 && col == n-1 && zouguo[row][col] == 0)
	{
		visit.push_back(make_pair(row, col));
		auto it = visit.begin();
		for (; it != visit.end(); it++)
		{
			cout << "(" << it->first << "," << it->second << ")" << endl;
		}
		visit.pop_back();
		return;
	}
	if (vec[row][col] == 0 && zouguo[row][col] == 0)
	{
		//cout << "row = " << row << " ; col = " << col << endl;
		zouguo[row][col] = 1;
		visit.push_back(make_pair(row, col));
		dfs(vec, zouguo, visit, row + 1, col, m, n);
		dfs(vec, zouguo, visit, row - 1, col, m, n);
		dfs(vec, zouguo, visit, row, col + 1, m, n);
		dfs(vec, zouguo, visit, row, col - 1, m, n);
		zouguo[row][col] = 0;
		visit.pop_back();
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int i, j;
		vector<vector<int>>vec(m);
		for (i = 0; i<m; i++)
			vec[i].resize(n);
		for (i = 0; i<m; i++)
		{
			for (j = 0; j<n; j++)
			{
				cin >> vec[i][j];
			}
		}
		vector<vector<int>>zouguo(m);  //判断路径有没有走过，防止进入无限循环的环路
		for (i = 0; i<m; i++)
			zouguo[i].resize(n,0);

		vector<pair<int, int>>visit;  //记录走过的路径，便于最后输出
		dfs(vec, zouguo, visit, 0, 0, m, n);
	}

	return 0;
}