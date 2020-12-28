#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
int n, k;
void solve() {
	cin >> n >> k;
	if (k > (n + 1) / 2) {
		cout << "-1\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				cout << ".";
			} else {
				if (i % 2 == 1 && k > 0) {
					cout << "R";
					k--;
				} else {
					cout << ".";
				}
			}
		}
		cout << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}