#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;


typedef struct Node
{
	int mkey;
	int mvalue;
	struct Node* next, *pre;
}*node;

class LRUCache
{
public:
	LRUCache(int c):cap(c)
	{
		usenum = 0;
		head = new struct Node;
		tail = new struct Node;
		head->pre = nullptr;
		head->next = tail;
		tail->pre = head;
		tail->next = nullptr;
	}
	~LRUCache()
	{
		delete head;
		delete tail;
	}
	void Put(int key, int value);
	int Get(int key);
	void PrintLRU();

private:
	node head, tail;
	unordered_map<int, node>mp;
	int usenum;  //��ǰ��ʹ�ø���
	const int cap;  //�ܵ�����
};

void LRUCache::Put(int key, int value)   //����
{
	node tmp = mp[key];
	if (tmp)  //������key���ڻ�����
	{
		tmp->mvalue = value;
	}
	else  //��Ҫ�½�
	{
		node p = new struct Node;
		p->mkey = key;
		p->mvalue = value;
		if (usenum == 0)  //��һ������
		{
			p->pre = nullptr;
			p->next = nullptr;
			head = p;
			tail = p;
			usenum++;
			mp[key] = head;
			return;
		}
		if (usenum < cap)  //��û��
		{
			usenum++;						
		}
		else  //���ˣ�ɾ��β�ڵ�
		{
			node del = tail;
			tail = tail->pre;
			mp.erase(del->mkey);
			delete del;
			tail->next = nullptr;			
		}
		p->next = head;
		p->pre = nullptr;
		head->pre = p;
		head = p;
		mp[key] = head;
	}
	PrintLRU();
}

int LRUCache::Get(int key)   //����
{
	node tmp = mp[key];
	if (tmp)  //�ŵ�ͷ�ڵ�
	{
		if (tmp == head)
		{
			return tmp->mvalue;
		}		
		if (tmp == tail)
		{
			tail = tmp->pre;  //����β�ڵ�
			tail->next = nullptr;
		}
		else
		{
			node t = tmp->pre;
			t->next = tmp->next;
			t = tmp->next;
			t->pre = tmp->pre;
		}
		tmp->next = head;
		head->pre = tmp;
		tmp->pre = nullptr;
		head = tmp;  //����ͷ�ڵ�
		mp[key] = head;
		PrintLRU();
		return head->mvalue;
	}
	else
	{
		PrintLRU();
		return -1;
	}		
}

void LRUCache::PrintLRU()
{
	cout << "====��ǰLRU=====" << endl;
	auto p = head;
	while (p != nullptr)
	{
		cout << p->mkey << "  " << p->mvalue << endl;
		p = p->next;
	}
	cout << "=============" << endl;
}

int main()
{
	int cap; char c;
	cout << "input LRUCache's size: ";
	cin >> cap;
	int mkey, mvalue, getv;
	LRUCache lru(cap);

	while (cin >> c)
	{
		if (c == 'p')  //p 1 1
		{
			cin >> mkey >> mvalue;
			lru.Put(mkey, mvalue);
		}
		if (c == 'g')  //g 1
		{
			cin >> getv;
			int res = lru.Get(getv);
			cout << "LRU->Get: " << res << endl;
		}
	}
	return 0;
}