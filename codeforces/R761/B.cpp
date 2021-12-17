#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
	ll n;
	cin >> n;
	if (n & 1) {
		auto cur = (n - 1) / 2;
		if (cur & 1) {
			cout << cur - 2 << " " << cur + 2 << " " << 1 << "\n";
		} else {
			cout << cur - 1 << " " << cur + 1 << " " << 1 << "\n";
		}
	} else {
		cout << 2 << " " << (n - 1) - 2 << " " << 1 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}