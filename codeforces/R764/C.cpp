#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n), vis(n, 0), can(n, 0);
	vector<vector<ll>> E(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		auto j = a[i];
		while (j) {
			if (j <= n && j > 0) {
				vis[j - 1]++;
				E[i].emplace_back(j - 1);
			}
			j /= 2;
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(E[i].begin(), E[i].end(),
			 [&](auto x, auto y) { return vis[x] < vis[y]; });
		for (auto j : E[i]) {
			if (can[j] == 0) {
				can[j] = 1;
				break;
			}
		}
	}
	for (auto i : can) {
		if (i == 0) {
			// cout << i << " ";
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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