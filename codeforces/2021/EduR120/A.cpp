#include <bits/stdc++.h>
using namespace std;
void solve() {
	int l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	if (l1 == l2 + l3 || l2 == l1 + l3 || l3 == l1 + l2 ||
		(l1 == l2 && l3 % 2 == 0) || (l1 == l3 && l2 % 2 == 0) ||
		(l2 == l3 && l1 % 2 == 0)) {
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