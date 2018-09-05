#include<iostream>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
const int MaxBranchNum = 10;

class TrieNode
{
public:
	string word;  //节点表示的单词
	string dis;
	int count;   //单词出现的次数
	TrieNode* nextBranch[MaxBranchNum];  //指向10个字符节点的指针 
public:
	TrieNode() :word(""), count(0),dis("")
	{
		memset(nextBranch, NULL, sizeof(TrieNode*)*MaxBranchNum);
	}
};

class Trie
{
public:
	Trie()
	{
		pRoot = new TrieNode();  //跟节点不放字符
	}
	~Trie()
	{
		Destory(pRoot);
	}
	void Insert(const string str,const string dist);
	int Search(const string str); //查找字符串str，并返回出现的次数
	void PrintAll();
private:
	TrieNode* pRoot;
private:
	void Destory(TrieNode* pRoot);
	void Print(TrieNode* pRoot);
};

void Trie::Insert(const string str, const string dist)  //存放前缀和地址
{
	int index;
	TrieNode* pLoc = pRoot;  //把当前树的根节点给pLoc
	for (int i = 0; i < str.size(); i++)
	{
		index = str[i] - '0';  
		if (index<0 || index>MaxBranchNum)
		{
			return;
		}
		if (NULL == pLoc->nextBranch[index])  //如果插入的字符串某个字符是以前没有的，就先new一个新的节点
		{
			pLoc->nextBranch[index] = new TrieNode();
		}
		pLoc = pLoc->nextBranch[index];
	}
	if (pLoc->word.size()>0)  
	{
		pLoc->count++;
		return;
	}
	else
	{
		pLoc->count++;
		pLoc->word = str;
		pLoc->dis = dist;
	}
}

int Trie::Search(const string str)
{
	int i = 0, index = -1, count = 0;
	TrieNode* pLoc = pRoot;
	TrieNode* pp;
	auto it = str.begin();
	bool isf = false;
	while (pLoc && it!=str.end())   //发现pLoc为空时或者字符串判断完时
	{
		index = *it - '0';
		if (index<0 || index>MaxBranchNum)
		{
			return 0;
		}
		pp = pLoc;  //记录上一个节点
		pLoc = pLoc->nextBranch[index];
		it++;
	}
	if (!pp->word.empty())  //找到了
	{
		cout << pp->dis << endl;
		return 1;
	}
	return 0;
}

void Trie::PrintAll()
{
	cout << "打印字典树：" << endl;
	Print(pRoot);
}
void Trie::Print(TrieNode* pRoot)
{
	if (NULL == pRoot)
		return;
	if (pRoot->word.size()>0)
	{
		cout << pRoot->word << " " << pRoot->dis << endl;
	}
	for (int i = 0; i < MaxBranchNum; i++)   //递归打印分支
	{
		Print(pRoot->nextBranch[i]);
	}
}
void Trie::Destory(TrieNode* pRoot)
{
	if (pRoot == NULL)
		return;
	for (int i = 0; i < MaxBranchNum; i++)
	{
		Destory(pRoot->nextBranch[i]);
	}
	if (pRoot->word.size()>0)
	{
		pRoot->word.clear();
		pRoot->count = 0;
	}
	delete pRoot;
	pRoot = NULL;
}


int main()
{
	int T, N, M;
	cin >> T;
	int i, maxlen, k;
	string qian, dist;

	for (int v = 0; v < T; v++)
	{		
		cin >> N;
		Trie t;
		vector<vector<string>>s(N);
		maxlen = 0;
		for (int c = 0; c < N; c++)
			s[c].resize(2);
		for (i = 0; i < N; i++)
		{
			cin >> qian;
			cin >> dist;
			string chuli;
			auto it = qian.begin();
			k = 0;
			for (; it != qian.end(); it++)
			{
				if (*it == 'x')
				{
					break;
				}
				k++;
				chuli.push_back(*it);
			}
			maxlen = maxlen > k ? maxlen : k;
			t.Insert(chuli, dist);
		}
		t.PrintAll();
		cin >> M;
		vector<string>res(M);
		for (i = 0; i<M; i++)
		{
			cin >> qian;
			res[i] = qian;
		}

		for (i = 0; i < M; i++)
		{
			int isFind = t.Search(res[i]);
			if (!isFind)
				cout << "unknown" << endl;
		}
	}
	return 0;
}

