#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, m, rb, cb, rd, cd;
	cin >> n >> m >> rb >> cb >> rd >> cd;
	ll r, c;
	if (rd >= rb) {
		r = rd - rb;
	} else {
		r = n - rb + n - rd;
	}
	if (cd >= cb) {
		c = cd - cb;
	} else {
		c = m - cb + m - cd;
	}
	cout << min(r, c) << "\n";
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