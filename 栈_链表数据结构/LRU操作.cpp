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
	int usenum;  //当前的使用个数
	const int cap;  //总的容量
};

void LRUCache::Put(int key, int value)   //插入
{
	node tmp = mp[key];
	if (tmp)  //新来的key已在缓存中
	{
		tmp->mvalue = value;
	}
	else  //需要新建
	{
		node p = new struct Node;
		p->mkey = key;
		p->mvalue = value;
		if (usenum == 0)  //第一个插入
		{
			p->pre = nullptr;
			p->next = nullptr;
			head = p;
			tail = p;
			usenum++;
			mp[key] = head;
			return;
		}
		if (usenum < cap)  //还没满
		{
			usenum++;						
		}
		else  //满了，删除尾节点
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

int LRUCache::Get(int key)   //查找
{
	node tmp = mp[key];
	if (tmp)  //放到头节点
	{
		if (tmp == head)
		{
			return tmp->mvalue;
		}		
		if (tmp == tail)
		{
			tail = tmp->pre;  //更新尾节点
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
		head = tmp;  //更新头节点
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
	cout << "====当前LRU=====" << endl;
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