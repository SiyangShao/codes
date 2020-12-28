#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> k(n), h(n);
	for (auto &i : k) {
		cin >> i;
	}
	for (auto &i : h) {
		cin >> i;
	}
	vector<pair<ll, ll>> seg;
	ll mana = 0;
	for (int i = 0; i < n; i++) {
		auto now = make_pair(k[i] - h[i] + 1, k[i]);
		while (!seg.empty() && now.first <= seg[seg.size() - 1].second) {
			if (now.first >= seg[seg.size() - 1].first)
				now.first = seg[seg.size() - 1].first;
			seg.pop_back();
		}
		seg.push_back(now);
	}
	for (auto &i : seg) {
		auto len = i.second - i.first + 1;
		mana += len * (len + 1) / 2;
	}
	cout << mana << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}