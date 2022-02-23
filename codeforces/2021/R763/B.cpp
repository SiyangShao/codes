#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>> a;
map<pair<int, int>, int> mp;
vector<pair<int, int>> E[1010];
int n;
bool dfs(int x) {
	if (x == n + 1) {
		return true;
	}
	for (auto i : E[x]) {
		if (mp[i] == 0) {
			mp[i] = 1;
			if (dfs(x + 1)) {
				cout << i.first << " " << i.second << " " << x << "\n";
				return true;
			}
			mp[i] = 0;
		}
	}
	return false;
}
void solve() {
	cin >> n;
	a.clear();
	a.resize(n);
	mp.clear();
	memset(E, 0, sizeof(E));
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		for (int j = a[i].first; j <= a[i].second; ++j) {
			E[j].emplace_back(a[i]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		sort(E[i].begin(), E[i].end(), [](pair<int, int> x, pair<int, int> y) {
			return x.second - x.first < y.second - y.first;
		});
	}
	dfs(1);
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