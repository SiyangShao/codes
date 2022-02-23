#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	ll n, m;
	while (t--) {
		cin >> n >> m;
		ll l, r, x;
		ll ans = 0;
		for (ll i = 1; i <= m; ++i) {
			cin >> l >> r >> x;
			ans = ans | x;
		}
		ans %= mod;
		ans = (ans * qpow(2, n - 1)) % mod;
		cout << ans << "\n";
	}
}