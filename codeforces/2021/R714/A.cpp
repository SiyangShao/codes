#include <bits/stdc++.h>
using namespace std;
int _, n, k;
int main() {
	cin >> _;
	while (_--) {
		cin >> n >> k;
		if (k > (n - 1) / 2) {
			cout << "-1\n";
		} else {
			vector<int> q;
			int i = 1;
			while (k--) {
				q.push_back(i);
				q.push_back(n + 1 - i);
				i++;
			}
			for (auto j : q) {
				cout << j << " ";
			}
			for (int j = i; j <= n + 1 - i; j++) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}
}