#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n, m, r, c;
	bool F = false;
	cin >> n >> m >> r >> c;
	vector<string> mp(n);
	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
		for (auto j : mp[i]) {
			if (j == 'B') {
				F = true;
				break;
			}
		}
	}
	r--, c--;
	if (mp[r][c] == 'B') {
		cout << "0\n";
		return;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (mp[i][c] == 'B') {
			flag = true;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (mp[r][i] == 'B') {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "1\n";
		return;
	}
	if (F) {
		cout << "2\n";
	} else {
		cout << "-1\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}