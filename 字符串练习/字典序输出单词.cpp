#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int input;
	while (cin >> input)
	{
		string str;
		vector<string> vs;
		while (input--)
		{
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());
		vector<string>::iterator vit;
		for (vit = vs.begin(); vit != vs.end(); vit++)
		{
			cout << *vit << endl;
		}
	}
	return 0;
}