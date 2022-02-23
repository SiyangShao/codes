#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 200005;
int n;
int a[maxn], c[31], r[maxn];
ll f[maxn];
ll qpow(ll a, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		p >>= 1;
	}
	return res;
}
int C(ll n, ll m) {
	return f[n] * qpow(f[m], mod - 2) % mod * qpow(f[n - m], mod - 2) % mod;
}

int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (f[i - 1] * i) % mod;
	}
	r[0] = 1;
	for (int i = 1; i <= n; i++) {
		r[i] = (r[i - 1] * 2) % mod;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int cnt = 0;
		for (; !(x & 1); x >>= 1)
			cnt++;
		c[cnt]++;
	}
	int ans = r[n] - 1;
	for (int i = 1; i <= 30; i++) {
		int tot = 0;
		for (int j = i + 1; j <= 30; j++)
			tot += c[j];
		for (int j = 1; j <= c[i]; j += 2) {
			ans -= 1LL * C(c[i], j) * r[tot] % mod;
			if (ans < 0)
				ans += mod;
		}
	}
	cout << ans;
	return 0;
}
