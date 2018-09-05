#include<iostream>
#include<vector>

using namespace std;

class query_tree {    //��Ҫ���ֵ����Ų��ᳬʱ�����ұ�m����λ����1����
public:
	query_tree *next[2]{ NULL,NULL };
	int count;
	query_tree() :count(1) { }  //count��ʼ��Ϊ1
};

query_tree root;  //ȫ��

void build_tree(int m) {
	query_tree *cur = &root;
	for (int j = 16; j >= 0; j--) {  //�����Ϊ��ʼ����д
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
��Ŀ����
��������m�Լ�n������A1,A2,..An��������A������Ԫ��������򣬹��ܵõ�n(n-1)/2��������������Щ����д���m���ж��ٸ���
��������:
��һ�а�����������n,m.

�ڶ��и���n������A1��A2��...��An��

���ݷ�Χ

����30%�����ݣ�1 <= n, m <= 1000

����100%�����ݣ�1 <= n, m, Ai <= 10^5
�������:
���������һ�У�������Ĵ�
ʾ��1
����

3 10
6 5 10
���

2
*/