#include<iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class Linklist
{
private:
	Node *Head;
public:
	Linklist();
	void CreateList(int n);
	void Insert(int i, int e);
	int Delete(int i);
	int ListLength();
};
#pragma once
