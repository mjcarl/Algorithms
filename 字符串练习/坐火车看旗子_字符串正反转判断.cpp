#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s, s1, s2;
	while (cin >> s)
	{
		cin >> s1;
		cin >> s2;
		string::size_type idx1, idx2;
		bool forwd = false, backwd = false;
		idx1 = s.find(s1);
		idx2 = s.rfind(s2);
		if (idx1 != string::npos && idx2 != string::npos)
		{
			if ((idx1 + s1.size()) <= idx2)
				forwd = true;
		}
		reverse(s.begin(), s.end());

		idx1 = s.find(s1);
		idx2 = s.rfind(s2);
		if (idx1 != string::npos && idx2 != string::npos)
		{
			if ((idx1 + s1.size()) <= idx2)
				backwd = true;
		}
		if (forwd == true && backwd == true)
			cout << "both" << endl;
		else if (forwd == true && backwd == false)
			cout << "forward" << endl;
		else if (forwd == false && backwd == true)
			cout << "backward" << endl;
		else
			cout << "invalid" << endl;
	}
	return 0;
}
