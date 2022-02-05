#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
vector<ll> tpow(2e5 + 10);
inline void init() {
	int two = tpow[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		if (two < i) {
			two *= 2;
		}
		tpow[i] = two - i;
	}
}
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	set<ll> left;
	for (ll i = 0; i <= n; i++) {
		if (i == 0 || i == n || a[i] != a[i - 1]) {
			left.insert(i);
		}
	}
	auto ans = INF;
	for (ll i = 0; i <= n; i++) {
		if (!left.count(i)) {
			continue;
		}
		for (ll b = 1; b <= n; b *= 2) {
			auto j = *prev(left.upper_bound(i + b));
			j = max(j, i);
			auto k = n - j;
			ans = min(ans, tpow[i] + tpow[j - i] + tpow[k]);
		}
	}
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	init();
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}