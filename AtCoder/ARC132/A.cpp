#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n;
vector<int> R, C;

void solve() {
	cin >> n;
	R.resize(n);
	C.resize(n);
	for (auto &i : R) {
		cin >> i;
	}
	for (auto &i : C) {
		cin >> i;
	}
	int q, r, c;
	cin >> q;
	while (q--) {
		cin >> r >> c;
		r--, c--;
		if (R[r] + C[c] >= n + 1) {
			cout << "#";
		} else {
			cout << ".";
		}
	}
	// for (auto i : E) {
	// 	for (auto j : i) {
	// 		cout << ((j == 1) ? "#" : ".");
	// 	}
	// 	cout << "\n";
	// }
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}