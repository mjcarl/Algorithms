#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point
{
public:
	int px;
	int py;
	bool visit;
public:
	Point(int x=0,int y=0) :px(x), py(y)
	{
		visit = false;
	}
	int getLength(Point p)
	{
		return abs(px - p.px) + abs(py - p.py);
	}
};

int mincost = 999999;
void dfs(Point start, Point p[], int sum, int count, int n);
int main()
{
	int n;
	cin >> n;
	int i, j, tmp;
	Point p[10];
	for (i = 0; i < n; i++)
	{
		cin >> p[i].px;
		if(cin.get()==',')
			cin >> p[i].py;
	}
	Point start(0, 0);
	dfs(start, p, 0, 0, n);

	cout << "min = " << mincost << endl;
	return 0;
}

void dfs(Point start, Point p[], int sum, int count, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].visit == false)
		{
			p[i].visit = true;
			sum = sum + start.getLength(p[i]);
			count++;
			if (count == n)
			{
				Point s(0, 0);
				sum = sum + p[i].getLength(s);
				if (sum < mincost)
					mincost = sum;
			}
			dfs(p[i], p, sum, count, n);
			p[i].visit = false;
			sum = sum - start.getLength(p[i]);
			count--;
		}
	}
}