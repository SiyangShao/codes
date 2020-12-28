#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> dp;
map<ll, vector<pair<ll, ll>>> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	dp.resize(n);
	for (ll i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		u--, v--;
		mp[w].push_back({u, v});
	}
	for (auto &[w, p] : mp) {
		map<ll, ll> cnt;
		for (auto &[u, v] : p) {
			if (cnt.count(u)) {
				cnt[u]++;
			} else {
				cnt[u] = dp[u] + 1;
			}
			cnt[u] += dp[v];
			if (cnt.count(v)) {
				cnt[v]++;
			} else {
				cnt[v] = dp[v] + 1;
			}
			cnt[v] += dp[u];
		}
		for (auto &[u, v] : cnt) {
			dp[u] = v;
		}
	}
	ll sum = 0;
	for (auto i : dp) {
		sum += i;
	}
	cout << sum;
}