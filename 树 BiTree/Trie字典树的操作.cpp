#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<assert.h>
using namespace std;
const int MaxBranchNum = 26;//������ִ�Сд��������չ��52  

class TrieNode
{
public:
	char* word;  //�ڵ��ʾ�ĵ���
	int count;   //���ʳ��ֵĴ���
	TrieNode* nextBranch[MaxBranchNum];  //ָ��26���ַ��ڵ��ָ��
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
		pRoot = new TrieNode();  //���ڵ㲻���ַ�
	}
	~Trie()
	{
		Destory(pRoot);
	}
	void Insert(const char* str);
	int Search(const char* str); //�����ַ���str�������س��ֵĴ���
	bool Remove(const char* str);
	void PrintAll();
	//void PrintPre(const char* str);  //��ӡstrΪǰ׺�ĵ���
private:
	TrieNode* pRoot;
private:
	void Destory(TrieNode* pRoot);
	void Print(TrieNode* pRoot);
};

void Trie::Insert(const char* str)
{
	assert(str != NULL);  //��������ʲô������ʾ��������ᱨ��
	int index;
	TrieNode* pLoc = pRoot;  //�ѵ�ǰ���ĸ��ڵ��pLoc
	for (int i = 0; i < strlen(str); i++)
	{
		index = str[i] - 'a';  //����ֻ��Сд
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
	if (NULL != pLoc->word)  //�˵����Ѿ����ڹ�
	{
		pLoc->count++;
		return;
	}
	else
	{
		pLoc->count++;
		pLoc->word = new char[strlen(str) + 1];  //��Ҫ��delete[]
		assert(NULL != pLoc->word);
		strcpy(pLoc->word, str);
	}
}

int Trie::Search(const char* str)
{
	assert(str != NULL);
	int i = 0, index = -1, count = 0;
	TrieNode* pLoc = pRoot;
	while (pLoc && *str)   //����pLocΪ��ʱ�����ַ����ж���ʱ
	{
		index = *str - 'a';
		if (index<0 || index>MaxBranchNum)
		{
			return 0;
		}
		pLoc = pLoc->nextBranch[index];
		str++;
	}
	if (pLoc && pLoc->word)  //�ҵ���
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

	for (i = 0; i < len && pLoc; i++) //ͬ while (pLoc && *str)
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
	cout << "��ӡ�ֵ�����" << endl;
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
	cout << "����ĵ��ʸ�����" ;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		t.Insert(p);
	}
	t.PrintAll();
	cout << "������ҵ��ʣ�" << endl;
	cin >> p;
	int isFind = t.Search(p);
	if (isFind > 0)
		cout << "���ֵĴ�����" << isFind << endl;
	else
		cout << "�����ڴ˵��ʣ�" << endl;
	t.PrintAll();
	cout << "����ɾ�����ʣ�" << endl;
	cin >> p;
	bool isDel = t.Remove(p);
	if (isDel)
	{
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��!" << endl;
	}
	t.PrintAll();
	return 0;
}
