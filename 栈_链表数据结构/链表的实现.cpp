#include<iostream>
#include"Linklist.h"

using namespace std;

int main()
{
	Linklist a;
	int n,e;
	cout << "input number of element: ";
	cin >> n;
	a.CreateList(n);
	a.ListLength();
	cout << "insert n and element: ";
	cin >> n >> e;
	a.Insert(n,e);
	a.ListLength();
	cout << "delete n: ";
	cin >> n;
	a.Delete(n);
	a.ListLength();
	return 0;
}