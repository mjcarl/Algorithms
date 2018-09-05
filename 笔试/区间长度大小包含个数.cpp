#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	while (cin >> n) {
		int cnt = 0;
		vector<int> arr(n), brr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			cin >> brr[i];
		for (int i = 0; i < n; i++) {
			if (arr[i] < brr[i])
				cnt++;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				arr[j] = max(arr[j], arr[j + 1]);
				brr[j] = min(brr[j], brr[j + 1]);
				if (arr[j] < brr[j])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}