#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col)
{
	vis[row][col] = true;
	if (row - 1 >= 0 && vis[row - 1][col] == false && grid[row - 1][col] == '1')  //向上
		dfs(grid, vis, row - 1, col);
	if (col - 1 >= 0 && vis[row][col - 1] == false && grid[row][col - 1] == '1')  //向左
		dfs(grid, vis, row, col - 1);
	if (row + 1<m && vis[row + 1][col] == false && grid[row + 1][col] == '1')  //向下
		dfs(grid, vis, row + 1, col);
	if (col + 1<n && vis[row][col + 1] == false && grid[row][col + 1] == '1')  //向右
		dfs(grid, vis, row, col + 1);
}
int numIslands(vector<vector<char>>& grid)
{
	int row, col;
	int i, j;
	int numofisland = 0;
	row = grid.size();  //行
    if(row==1)
        return 0;
	col = grid[0].size();  //列
	vector<std::vector<bool>> vis(row);
	for (i = 0; i<row; i++)
		vis[i].resize(col);
	for (i = 0; i<row; i++)
		for (j = 0; j<col; j++)
		{
			vis[i][j] = false;
		}
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			if (vis[i][j] == false && grid[i][j] == '1')
			{
				numofisland++;
				dfs(grid, vis, i, j);
			}
		}
	}
	return numofisland;
}


int main()
{
	cin >> m >> n;
	int i, j;
	vector<std::vector<char>> grid(m);
	for (i = 0; i<m; i++)
		grid[i].resize(n);
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << numIslands(grid) << endl;
	return 0;
}
