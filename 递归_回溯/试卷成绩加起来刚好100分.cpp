#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//此题可谓遍历了整个数组的所有可能  1.对数组排序 2. 以深度为参数进行循环 3. 递归先判断条件，在进行for循环递归遍历。记着给深度加1

#define SCORE 100
int N;
vector<int> a;
bool x[100];   //表示这个数当前是否在sum里
int sum = 0;
int num = 0;
void backtrace(int deep)  //deep表示深度
{
	if(sum > SCORE)
		return;
	if (sum == SCORE)
	{
		cout << "题数：" << num << endl;
		for (int i = 0; i < N; i++)
		{
			if (x[i] == true)
				cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	if (deep == N)
		return;
	for (int j = deep; j < N; j++)
	{
		if (x[j] == false)
		{
			x[j] = true;
			sum += a[j];
			num++;
			backtrace(j + 1);   //注意是j+1
			x[j] = false;
			sum -= a[j];
			num--;
			while (j < N - 1 && a[j] == a[j + 1])   //过掉重复元素   比如输入20 40 40 40...  结果输出20 40 40
				++j;
		}		
	}
}


int main()
{	
	cin >> N;
	int tmp;	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());  //排序  防止重复元素干扰	
	backtrace(0);

	return 0;
}