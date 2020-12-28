#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef pair<pair<int, int>, int> PPI;

int n;
void solve() {
	cin >> n;
	auto cmpL = [](PPI a, PPI b) {
		if (a.first.first != b.first.first) {
			return a.first.first > b.first.first;
		} else {
			return a.second > b.second;
		}
	};
	auto cmpR = [](PPI a, PPI b) {
		if (a.first.second != b.first.second) {
			return a.first.second < b.first.second;
		} else {
			return a.second > b.second;
		}
	};
	priority_queue<PPI, vector<PPI>, decltype(cmpL)> x(cmpL);
	priority_queue<PPI, vector<PPI>, decltype(cmpR)> y(cmpR);
	int l = -1, r = -1, ma = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		x.push({{u, v}, w});
		y.push({{u, v}, w});
		if (l == -1)
			l = u;
		if (r == -1)
			r = v;
		if (l == u && r == v) {
			ma = min(ma, w);
		} else if (l > u || r < v) {
			l = min(l, u);
			r = max(r, v);
			if (l == u && r == v) {
				ma = w;
			} else {
				ma = 0x3f3f3f3f3f3f3f3f;
			}
		}
		auto X = x.top(), Y = y.top();
		if (X.first.first == Y.first.first &&
			X.first.second == Y.first.second) {
			cout << min(ma, min(X.second, Y.second)) << "\n";
		} else if (X.first.first == Y.first.first) {
			cout << min(ma, Y.second) << "\n";
		} else if (X.first.second == Y.first.second) {
			cout << min(ma, X.second) << "\n";
		} else {
			cout << min(ma, X.second + Y.second) << "\n";
		}
	}
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