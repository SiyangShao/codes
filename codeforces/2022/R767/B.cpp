#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll l, r, k;
	cin >> l >> r >> k;
	if (l == r) {
		if (l == 1ll) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
		return;
	}
	ll odd = (r + 1) / 2 - l / 2;
	if (odd <= k) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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