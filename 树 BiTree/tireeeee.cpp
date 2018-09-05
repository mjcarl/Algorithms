#include <iostream>
#include <vector>
using namespace std;

struct TrieTree
{
	int count;//ÿ���ڵ��Ĵ���
	struct TrieTree* next[2]{ NULL,NULL };//ÿ���ڵ�洢�����ڵ�ָ��
	TrieTree() :count(1) {}
};

TrieTree* buildTrieTree(const vector<int>& array)
{
	TrieTree* trieTree = new TrieTree();
	for (int i = 0; i<(int)array.size(); ++i)
	{
		TrieTree* cur = trieTree;
		for (int j = 16; j >= 0; --j)
		{
			int digit = (array[i] >> j) & 1;
			if (NULL == cur->next[digit])
				cur->next[digit] = new TrieTree();
			else
				++(cur->next[digit]->count);
			cur = cur->next[digit];
		}
	}
	return trieTree;
}

//��ѯ�ֵ���
long long queryTrieTree(TrieTree*& trieTree, const int a, const int m, const int index)
{
	if (NULL == trieTree)
		return 0;

	TrieTree* cur = trieTree;

	for (int i = index; i >= 0; --i)
	{
		int aDigit = (a >> i) & 1;
		int mDigit = (m >> i) & 1;

		if (1 == aDigit && 1 == mDigit)
		{
			if (NULL == cur->next[0])
				return 0;
			cur = cur->next[0];
		}
		else if (0 == aDigit && 1 == mDigit)
		{
			if (NULL == cur->next[1])
				return 0;
			cur = cur->next[1];
		}
		else if (1 == aDigit && 0 == mDigit)
		{
			long long val0 = (NULL == cur->next[0]) ? 0 : cur->next[0]->count;
			long long val1 = queryTrieTree(cur->next[1], a, m, i - 1);
			return val0 + val1;
		}
		else if (0 == aDigit && 0 == mDigit)
		{
			long long val0 = queryTrieTree(cur->next[0], a, m, i - 1);
			long long val1 = (NULL == cur->next[1]) ? 0 : cur->next[1]->count;
			return val0 + val1;
		}
	}
	return 0;//��ʱindex==-1,��������϶�����0�����������ѭ�����ж����ǵ��ˣ�
}

//������ܳ�����int��Χ�������long long
long long solve(const vector<int>& array, const int& m)
{
	TrieTree* trieTree = buildTrieTree(array);
	long long result = 0;
	for (int i = 0; i<(int)array.size(); ++i)
	{
		result += queryTrieTree(trieTree, array[i], m, 16);
	}
	return result / 2;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> array(n);
		for (int i = 0; i<n; ++i)
			cin >> array[i];
		cout << solve(array, m) << endl;
	}
	return 0;
}