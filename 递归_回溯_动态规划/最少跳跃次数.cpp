#include <iostream>
#include<vector>
#include<string>
using namespace std;

int min(int a, int b);
//void canJump(int pos, vector<int>&mindis, vector<int>&arr);
//int minDis = 999;
int main()
{
	int N;
	cin >> N;
	vector<int>arr(N);
	vector<int>mindis(N,999);
	int i, j;
	mindis[0] = 0;
	for (i = 0; i < N; i++)
	{
		cin >> j;
		arr[i] = j;
	}
	//canJump(0, mindis, arr);
	for (i = 0; i < N; i++)
	{
		for (j = 1; j <= arr[i] && (i+j)<=N-1; j++)
		{
			mindis[i + j] = min(mindis[i + j], mindis[i] + 1);
		}
	}
	cout << "min dis is " << mindis[N - 1] << endl;

	//cout << "结果为： " << minDis << endl;
	return 0;
}


//void canJump(int pos, vector<int>&mindis, vector<int>&arr)
//{
//	if (pos == arr.size() - 1)
//	{
//		minDis = min(minDis, mindis[pos]);
//	}
//
//	int jump = min(pos + arr[pos], arr.size() - 1);   //最远可以跳到的位置
//	for (int nextpos = pos + 1; nextpos <= jump; nextpos++)
//	{
//		mindis[nextpos] = mindis[pos] + 1;
//		cout << "mindis[nextpos]： " << mindis[nextpos] << endl;
//		canJump(nextpos, mindis, arr);
//		mindis[nextpos] = mindis[pos] - 1;
//	}
//
//}

int min(int a,int b)
{
	return a < b ? a : b;
}