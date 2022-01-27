#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), suff(n), ans;
	unordered_map<int, int> vis;
	for (auto &i : a) {
		cin >> i;
	}
	auto cnt = suff.rbegin();
	auto l = 0;
	for (auto i = a.rbegin(); i < a.rend(); ++i) {
		vis[*i] = 1;
		while (vis[l])
			l++;
		*cnt = l;
		cnt++;
	}
	vis.clear();
	l = 0;
	auto x = suff[0];
	for (int i = 0; i < n; ++i) {
		vis[a[i]] = 1;
		while (vis[l]) {
			l++;
		}
		if (l == x) {
			ans.emplace_back(l);
			l = 0;
			if (i + 1 < n)
				x = suff[i + 1];
			for (int p = x; p >= 0; p--) {
				vis[p] = 0;
			}
		}
	}
	cout << ans.size() << "\n";
	for (const auto &i : ans) {
		cout << i << " ";
	}
	cout << "\n";
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