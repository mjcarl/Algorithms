#include <iostream>
#include <vector>
using namespace std;

unsigned int maxCost = 0;
unsigned int num_path = 0;

void dfs(unsigned int costNow, int v, vector<vector<int> > &relation, vector<int> &cost, vector<int> &visit, int n)
{
	if (v >= n || relation[v].size() == 0)
	{
		if (costNow > maxCost)
		{
			maxCost = costNow;
		}
		num_path++;
	}
	visit[v] = 1;
	size_t i;
	for (i = 0; i<relation[v].size(); i++)
	{
		if (visit[relation[v][i]]==0)
		{
			dfs(costNow + cost[relation[v][i]], relation[v][i], relation, cost, visit, n);
		}
	}
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	vector<vector<int>> relation;
	for (i = 0; i < n; i++)
		relation[i].resize(n);
	vector<int> cost(n);
	vector<int> head(n, 1);  //可以作为开头的节点
	vector<int> visit(n, 0);

	for (i = 0; i<n; i++)
	{
		cin >> cost[i];
	}

	int a, b;
	for (i = 0; i<m; i++)
	{
		cin >> a >> b;
		relation[a - 1].push_back(b - 1);
		head[b - 1] = 0;
	}

	for (i = 0; i<n; i++)
	{		
		if (head[i]==1)
			dfs(cost[i], i, relation, cost, visit, n);
	}
	cout << num_path << " " << maxCost << endl;
	return 0;
}