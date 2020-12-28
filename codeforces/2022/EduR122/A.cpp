#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n;
	cin >> n;
	if (n % 7 == 0) {
		cout << n << "\n";
		return;
	}
	auto x = (n / 10);
	auto l = x * 10, r = (x + 1) * 10 - 1;
	for (auto i = l; i <= r; ++i) {
		if (i % 7 == 0) {
			cout << i << "\n";
			return;
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