#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
inline ll check(ll a, ll b) { return (a | b) - b + 1; }
void solve() {
	ll a, b;
	cin >> a >> b;
	ll ans = b - a;
	for (ll i = 0; i < (b - a); ++i) {
		ans = min(ans, check(a + i, b) + i);
		ans = min(ans, check(a, b + i) + i);
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