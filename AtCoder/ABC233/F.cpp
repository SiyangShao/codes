#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> fa;
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> b(n);
	fa.resize(n);
	iota(fa.begin(), fa.end(), 0);
	for (auto &i : a) {
		cin >> i;
		i--;
	}
	int m;
	cin >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		u--, v--;
		merge(u, v);
	}
	for (int i = 0; i < n; ++i) {
		b[i].first = a[i];
		b[i].second = find(a[i]);
	}
	sort(b.begin(), b.end(),
		 [](pair<int, int> x, pair<int, int> y) { return x.first < y.first; });
	for (int i = 0; i < n; ++i) {
		if (b[i].second != find(a[i])) {
			cout << "-1\n";
			return;
		}
	}
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}