#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pair_hash {
	template <class T1, class T2>
	auto operator()(const pair<T1, T2> &pair) const {
		return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
	}
};
constexpr ll INF = INT_MAX;
map<ll, ll> mp;
map<pair<ll, ll>, ll> vis;
void solve() {
	ll n, m;
	cin >> n >> m;
	mp.clear(), vis.clear();
	for (ll i = 0, x; i < n; ++i) {
		cin >> x;
		mp[x]++;
	}
	for (ll i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		vis[{x, y}] = 1;
		vis[{y, x}] = 1;
	}
	vector<vector<ll>> ans(n);
	for (const auto &[x, y] : mp) {
		ans[y].emplace_back(x);
	}
	for (auto &i : ans) {
		reverse(i.begin(), i.end());
	}
	ll answer = 0;
	for (ll cnt_x = 1; cnt_x < n; cnt_x++)
		for (auto x : ans[cnt_x])
			for (ll cnt_y = 1; cnt_y <= cnt_x; cnt_y++)
				for (auto y : ans[cnt_y])
					if (x != y && !vis[{x, y}]) {
						answer = max(answer, 1ll * (cnt_x + cnt_y) * (x + y));
						break;
					}

	cout << answer << '\n';
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