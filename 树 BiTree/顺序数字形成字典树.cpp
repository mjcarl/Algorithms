#include<iostream>
#include<vector>
#include<string>
#define MaxNum 10
using namespace std;
int res = 0, x = 0;


struct TrieNode
{
	int s;
	struct TrieNode* next[MaxNum]={NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	TrieNode() :s(-1) { }
};



void CreateTire(int n,TrieNode* pRoot)
{
	TrieNode* pLoc = pRoot;
	for (int i = 1; i <= n; i++)
	{
		string a = to_string(i);
		auto it = a.begin();
		int tmp;
		pLoc = pRoot;
		while(it!=a.end())
		{
			tmp = *it - '0';
			if (NULL == pLoc->next[tmp])
			{
				pLoc->next[tmp] = new TrieNode();
			}
			if (it == a.end() - 1)
			{
				pLoc->next[tmp]->s = i;
				break;
			}
			pLoc = pLoc->next[tmp];
			it++;
		}
	}
}

void NumM(int m,  TrieNode* pRoot)
{
	TrieNode* pLoc = pRoot;
	if (NULL == pRoot)
		return;
	if (pLoc->s != -1)
	{
		x++;
		if (x == m)
		{
			res = pLoc->s;
		}
	}
	for(int i=0;i<MaxNum && res==0;i++)
	{
		NumM(m, pLoc->next[i]);
	}
}

void Print(TrieNode* pRoot)
{
	if (NULL == pRoot)
		return;
	if (pRoot->s != -1)
	{
		cout << "ooouuuu= " << pRoot->s << endl;
	}
	for (int i = 0; i < MaxNum; i++)   //递归打印分支
	{
		Print(pRoot->next[i]);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	TrieNode* pRoot = new TrieNode();
	CreateTire(n,pRoot);
	//Print(pRoot);
	NumM(m,pRoot);
	cout << res << endl;

	return 0;
}

/*
给定整数n和m, 将1到n的这n个整数按字典序排列之后, 求其中的第m个数。
对于n=11, m=4, 按字典序排列依次为1, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9,
*/
