#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, X, l, num = 0;
vector<vector<ll>> a;
ll dfs(ll x, ll Product) {
	if (x == N) {
		if (Product == 1)
			return 1;
		else
			return 0;
	}
	ll ans = 0;
	for (auto i : a[x]) {
		if (Product < i) {
			break;
		}
		if (Product % i == 0) {
			ans += dfs(x + 1, Product / i);
		}
	}
	return ans;
}
void solve() {
	cin >> N >> X;
	a.resize(N);
	for (auto &i : a) {
		cin >> l;
		i.resize(l);
		for (auto &j : i) {
			cin >> j;
		}
		sort(i.begin(), i.end());
	}
	cout << dfs(0, X);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}