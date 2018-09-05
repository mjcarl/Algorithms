#include<bits/stdc++.h>
using namespace std;

int main()
{
	list<int>lst, lst2;
	for (int i = 0; i < 5; i++)
		lst.push_back(5-i);
	for (int j = 0; j < 5; j++)
		lst2.push_back(10 - j);
	lst.merge(lst2, greater<int>());   //Ωµ–Ú≈≈¡–
	for (auto &ii : lst)
		cout << ii << " ";
	cout << endl;
	lst.sort();
	for (auto &ii : lst)
		cout << ii << " ";

	return 0;
}