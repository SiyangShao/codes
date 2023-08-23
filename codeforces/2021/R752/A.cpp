#include <bits/stdc++.h>
using namespace std;
int main() {
	int _, n;
	int a[101];
	cin >> _;
	while (_--) {
		cin >> n;
		int insert = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] > i + insert) {
				insert = a[i] - i;
			}
		}
		cout << insert << "\n";
	}
}