#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<assert.h>
using namespace std;
const int MaxBranchNum = 26;//如果区分大小写，可以扩展到52  

class TrieNode
{
public:
	char* word;  //节点表示的单词
	int count;   //单词出现的次数
	TrieNode* nextBranch[MaxBranchNum];  //指向26个字符节点的指针
public:
	TrieNode() :word(NULL), count(0)
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
	void Insert(const char* str);
	int Search(const char* str); //查找字符串str，并返回出现的次数
	bool Remove(const char* str);
	void PrintAll();
	//void PrintPre(const char* str);  //打印str为前缀的单词
private:
	TrieNode* pRoot;
private:
	void Destory(TrieNode* pRoot);
	void Print(TrieNode* pRoot);
};

void Trie::Insert(const char* str)
{
	assert(str != NULL);  //满足条件什么都不显示，不满足会报错
	int index;
	TrieNode* pLoc = pRoot;  //把当前树的根节点给pLoc
	for (int i = 0; i < strlen(str); i++)
	{
		index = str[i] - 'a';  //暂且只有小写
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
	if (NULL != pLoc->word)  //此单词已经存在过
	{
		pLoc->count++;
		return;
	}
	else
	{
		pLoc->count++;
		pLoc->word = new char[strlen(str) + 1];  //需要用delete[]
		assert(NULL != pLoc->word);
		strcpy(pLoc->word, str);
	}
}

int Trie::Search(const char* str)
{
	assert(str != NULL);
	int i = 0, index = -1, count = 0;
	TrieNode* pLoc = pRoot;
	while (pLoc && *str)   //发现pLoc为空时或者字符串判断完时
	{
		index = *str - 'a';
		if (index<0 || index>MaxBranchNum)
		{
			return 0;
		}
		pLoc = pLoc->nextBranch[index];
		str++;
	}
	if (pLoc && pLoc->word)  //找到了
	{
		count = pLoc->count;
		return count;
	}
	return 0;
}

bool Trie::Remove(const char* str)
{
	TrieNode* pLoc = pRoot;
	int index, i, len = strlen(str);

	for (i = 0; i < len && pLoc; i++) //同 while (pLoc && *str)
	{
		index = *str - 'a';
		if (index<0 || index>MaxBranchNum)
		{
			return false;
		}
		pLoc = pLoc->nextBranch[index];		
		str++;		
	}

	if (pLoc && pLoc->word)
	{
		delete[] pLoc->word;
		pLoc->word = NULL;
		pLoc->count = 0;
		return true;
	}
	return false;
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
	if (pRoot->word != NULL)
	{
		cout << pRoot->word << " " << pRoot->count << endl;
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
	if (NULL != pRoot->word)
	{
		delete[] pRoot->word;
		pRoot->word = NULL;
		pRoot->count = 0;
	}
	delete pRoot;
	pRoot = NULL;
}

int main()
{
	Trie t;
	char p[20];
	int N = 1;
	cout << "输入的单词个数：" ;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		t.Insert(p);
	}
	t.PrintAll();
	cout << "输入查找单词：" << endl;
	cin >> p;
	int isFind = t.Search(p);
	if (isFind > 0)
		cout << "出现的次数：" << isFind << endl;
	else
		cout << "不存在此单词！" << endl;
	t.PrintAll();
	cout << "输入删除单词：" << endl;
	cin >> p;
	bool isDel = t.Remove(p);
	if (isDel)
	{
		cout << "删除成功!" << endl;
	}
	else
	{
		cout << "删除失败!" << endl;
	}
	t.PrintAll();
	return 0;
}
