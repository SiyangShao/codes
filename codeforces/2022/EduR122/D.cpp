#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e3 + 7;
vector<ll> mp(N, N);
void init() {
	mp[1] = 0;
	for (ll i = 1; i < N; ++i) {
		for (ll x = 1; x <= i; ++x) {
			ll j = i + i / x;
			if (j < N) {
				mp[j] = min(mp[j], mp[i] + 1);
			}
		}
	}
}
void solve() {
	ll n, k, sum = 0;
	cin >> n >> k;
	vector<ll> dp(k + 1, 0);
	vector<ll> b(n), c(n);
	for (auto &i : b) {
		cin >> i;
		sum += mp[i];
	}
	k = k < sum ? k : sum;
	for (auto &i : c) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		// cout << mp[b[i]] << " ";
		for (int l = k; l >= mp[b[i]]; --l) {
			dp[l] = max(dp[l], dp[l - mp[b[i]]] + c[i]);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
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