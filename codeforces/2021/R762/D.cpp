#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> mp[100010];
inline void solve() {
	int m, n;
	cin >> m >> n;
	memset(mp, 0, sizeof(mp));
	vector<vector<int>> E(m);
	int minu = 1e9 + 7;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1, u; j <= n; ++j) {
			cin >> u;
			E[i - 1].push_back(u);
			minu = min(minu, u);
			mp[j].push_back({u, i});
		}
	}
	if (m == 1) {
		cout << minu << "\n";
		return;
	}
	unordered_map<int, int> cnt;
	minu = 1e9 + 7;
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		sort(mp[i].begin(), mp[i].end(),
			 [](pair<int, int> x, pair<int, int> y) {
				 return x.first > y.first;
			 });
		cnt[mp[i][0].second]++;
		if (cnt[mp[i][0].second] > 1) {
			flag = true;
		}
		minu = min(mp[i][0].first, minu);
		// for (auto i : mp[i]) {
		// 	cout << i.first << ":" << i.second << " ";
		// }
		// cout << "\n";
	}
	if (flag) {
		cout << minu << "\n";
		return;
	}
	int re = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (cnt[mp[i][j].second]) {
				if (mp[i][j].first > minu) {
					cout << minu << "\n";
					return;
				} else {
					re = max(re, mp[i][j].first);
					break;
				}
			} else {
				bool flag = false;
				int tmp = mp[i][j].second, tim = 0, lea = mp[i][j].first;
				for (int k = 0; k < n; ++k) {
					if (E[tmp-1][k] >= lea) {
						tim++;
					}
					if (tim >= 2) {
						flag = true;
						re = max(re, mp[i][j].first);
						break;
					}
				}
				if (flag) {
					break;
				}
			}
		}
	}
	cout << min(re, minu) << "\n";
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