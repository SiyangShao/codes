#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll N = 5007;
vector<ll> fac(N + 7), inv(N + 7);
inline ll qpow(ll x, ll n) {
	ll ans = 1;
	while (n) {
		if (n % 2)
			ans = (ans * x) % mod;
		x = (x * x) % mod;
		n /= 2;
	}
	return ans;
}
inline void init() {
	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[N] = qpow(fac[N], mod - 2);
	for (int i = N - 1; i >= 1; i--) {
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
}
inline ll C(ll x, ll y) {
	if (x == 0 || y == 0 || x == y)
		return 1;
	return fac[x] * inv[x - y] % mod * inv[y] % mod;
}
void solve() {
	ll n, k;
	string s;
	cin >> n >> k >> s;
	vector<ll> vs;
	vs.emplace_back(0);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			vs.emplace_back(i + 1);
		}
	}
	vs.emplace_back(n + 1);
	if (k == 0 || k > vs.size() - 2) {
		cout << 1 << "\n";
		return;
	}
	ll ans = 0;
	for (int i = 1; i + k < vs.size(); ++i) {
		ll l = vs[i - 1] + 1, r = vs[i + k] - 1;
		ll L = r - l + 1;
		// cout << L << " " << C(L, k) << "\n";
		ans = (ans + C(L, k)) % mod;
		if (i > 1) {
			l = vs[i - 1] + 1, r = vs[i + k - 1] - 1;
			L = r - l + 1;
			ans = (ans - C(L, k - 1) + mod) % mod;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	init();
	while (_--) {
		solve();
	}
}