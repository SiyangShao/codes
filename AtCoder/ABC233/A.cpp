#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll x, y;
	cin >> x >> y;
	if (y < x) {
		cout << "0\n";
	} else if ((y - x) % 10 == 0) {
		cout << (y - x) / 10 << "\n";
	} else {
		cout << 1 + (y - x) / 10 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}