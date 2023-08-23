#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n, a, b;
void solve() {
	cin >> n >> a >> b;
	vector<int> X(a), Y(b);
	for (auto &i : X) {
		cin >> i;
	}
	for (auto &i : Y) {
		cin >> i;
	}
	int t;
	for (int i = 1; i <= n; ++i) {
		t = 0;
		for (auto j : X) {
			if (i == j) {
				t = 1;
				break;
			}
		}
		if (t) {
			cout << 1 << " ";
		} else {
			cout << 2 << " ";
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}