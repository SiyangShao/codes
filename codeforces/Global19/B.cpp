#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 0) {
			b[i] = b[i - 1] + 1;
		} else {
			b[i] = b[i - 1];
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			ans += (j - i + 1) + b[j] - b[i - 1];
		}
	}
	cout << ans << "\n";
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