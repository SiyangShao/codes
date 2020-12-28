#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n;
	cin >> n;
	unordered_map<ll, ll> mp;
	vector<ll> a(n);
	vector<vector<ll>> b(n + 1);
	ll cnt = 0;
	for (auto &i : a) {
		cin >> i;
	}
	for (auto i = a.begin(); i < a.end(); ++i) {
		if (mp[*i] == 0) {
			mp[*i] = ++cnt;
		}
		b[mp[*i]].emplace_back(i - a.begin());
	}
	ll ans = -1;
	for (int i = 1; i <= cnt; ++i) {
		for (auto j = b[i].begin(); j + 1 < b[i].end(); ++j) {
			auto L = (*j - 0), R = n - *(j + 1);
			ans = max(ans, L + R);
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