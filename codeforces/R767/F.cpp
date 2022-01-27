#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 1e6 + 7;
ll n, m, k;
ll fac[N], ifac[N], ipw[N];
ll qpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % MOD;
		}
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}
ll fractionMod(ll a, ll b, ll p = MOD) {
	return ((a % p) * qpow(b, p - 2)) % p;
}
void init() {
	fac[0] = 1, ipw[0] = 1, ifac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	ifac[N - 1] = qpow(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
	for (int i = 1; i < N; ++i) {
		ipw[i] = ipw[i - 1] * (MOD + 1) / 2 % MOD;
	}
}
inline ll C(ll n, ll m) {
	if (n < 0 || n < m || m < 0)
		return 0;
	return fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}
void solve() {
	cin >> n >> m >> k;
	ll ans = 0;
	if (n == m) {
		cout << k * m % MOD << "\n";
		return;
	}
	for (int i = 1; i <= m; ++i) {
		ans =
			(ans + C(n - i - 1, m - i) * i % MOD * k % MOD * ipw[n - i]) % MOD;
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	init();
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}