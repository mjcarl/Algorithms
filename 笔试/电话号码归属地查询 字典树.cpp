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
	string word;  //�ڵ��ʾ�ĵ���
	string dis;
	int count;   //���ʳ��ֵĴ���
	TrieNode* nextBranch[MaxBranchNum];  //ָ��10���ַ��ڵ��ָ�� 
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
		pRoot = new TrieNode();  //���ڵ㲻���ַ�
	}
	~Trie()
	{
		Destory(pRoot);
	}
	void Insert(const string str,const string dist);
	int Search(const string str); //�����ַ���str�������س��ֵĴ���
	void PrintAll();
private:
	TrieNode* pRoot;
private:
	void Destory(TrieNode* pRoot);
	void Print(TrieNode* pRoot);
};

void Trie::Insert(const string str, const string dist)  //���ǰ׺�͵�ַ
{
	int index;
	TrieNode* pLoc = pRoot;  //�ѵ�ǰ���ĸ��ڵ��pLoc
	for (int i = 0; i < str.size(); i++)
	{
		index = str[i] - '0';  
		if (index<0 || index>MaxBranchNum)
		{
			return;
		}
		if (NULL == pLoc->nextBranch[index])  //���������ַ���ĳ���ַ�����ǰû�еģ�����newһ���µĽڵ�
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
	while (pLoc && it!=str.end())   //����pLocΪ��ʱ�����ַ����ж���ʱ
	{
		index = *it - '0';
		if (index<0 || index>MaxBranchNum)
		{
			return 0;
		}
		pp = pLoc;  //��¼��һ���ڵ�
		pLoc = pLoc->nextBranch[index];
		it++;
	}
	if (!pp->word.empty())  //�ҵ���
	{
		cout << pp->dis << endl;
		return 1;
	}
	return 0;
}

void Trie::PrintAll()
{
	cout << "��ӡ�ֵ�����" << endl;
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
	for (int i = 0; i < MaxBranchNum; i++)   //�ݹ��ӡ��֧
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

