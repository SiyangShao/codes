#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	ll bit = 0;
	for (auto &i : a) {
		cin >> i;
		bit ^= (i & 1);
	}
	if (bit ^ (y & 1)) {
		if (x & 1) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	} else {
		if (x & 1) {
			cout << "Bob\n";
		} else {
			cout << "Alice\n";
		}
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