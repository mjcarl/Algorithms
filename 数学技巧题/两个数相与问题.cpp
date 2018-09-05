#include<iostream>
#include<vector>

using namespace std;

class query_tree {    //需要用字典树才不会超时，查找比m更高位还有1的数
public:
	query_tree *next[2]{ NULL,NULL };
	int count;
	query_tree() :count(1) { }  //count初始化为1
};

query_tree root;  //全局

void build_tree(int m) {
	query_tree *cur = &root;
	for (int j = 16; j >= 0; j--) {  //从最高为开始往下写
		bool flag = m >> j & 1;
		if (!cur->next[flag]) {
			cur->next[flag] = new query_tree;
		}
		else
			cur->next[flag]->count++;
		cur = cur->next[flag];
	}
}

long long query_num(int n, int m, query_tree *root, int index) {
	if (index<0)
		return 0;
	int n_i = n >> index & 1;
	int m_i = m >> index & 1;
	if (n_i == 1 && m_i == 1) {
		return root->next[0] ? query_num(n, m, root->next[0], index - 1) : 0;
	}
	else if (n_i == 1 && m_i == 0) {
		long long val1 = root->next[0] ? root->next[0]->count : 0;
		long long val2 = root->next[1] ? query_num(n, m, root->next[1], index - 1) : 0;
		return val1 + val2;
	}
	else if (n_i == 0 && m_i == 1) {
		return root->next[1] ? query_num(n, m, root->next[1], index - 1) : 0;
	}
	else {
		long long val1 = root->next[1] ? root->next[1]->count : 0;
		long long val2 = root->next[0] ? query_num(n, m, root->next[0], index - 1) : 0;
		return val1 + val2;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vi(n);
	long long count = 0;
	for (int i = 0; i<n; i++) {
		cin >> vi[i];
		build_tree(vi[i]);
	}
	for (int i = 0; i<n; i++)
		count += query_num(vi[i], m, &root, 16);
	cout << count / 2 << endl;
	return 0;
}

/*
题目描述
给定整数m以及n各数字A1,A2,..An，将数列A中所有元素两两异或，共能得到n(n-1)/2个结果，请求出这些结果中大于m的有多少个。
输入描述:
第一行包含两个整数n,m.

第二行给出n个整数A1，A2，...，An。

数据范围

对于30%的数据，1 <= n, m <= 1000

对于100%的数据，1 <= n, m, Ai <= 10^5
输出描述:
输出仅包括一行，即所求的答案
示例1
输入

3 10
6 5 10
输出

2
*/