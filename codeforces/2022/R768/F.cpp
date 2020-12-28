#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (auto &i : a) {
		cin >> i;
	}
	ll d = 0;
	for (auto &i : b) {
		cin >> i;
		d = gcd(d, i);
	}
	vector<vector<ll>> dp(d, vector<ll>(2));
	for (auto &i : dp) {
		i[1] = INT_MIN;
	}
	for (ll i = 0; i < n; ++i) {
		ll rem = i % d;
		ll v0 = max(dp[rem][0] + a[i], dp[rem][1] - a[i]);
		ll v1 = max(dp[rem][0] - a[i], dp[rem][1] + a[i]);
		dp[rem][0] = v0, dp[rem][1] = v1;
	}
	ll sum0 = 0, sum1 = 0;
	for (auto i : dp) {
		sum0 += i[0];
		sum1 += i[1];
	}
	cout << max(sum0, sum1) << "\n";
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