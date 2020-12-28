#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
int n;
vector<vector<int>> mp;
void solve() {
	cin >> n;
	mp.clear();
	mp.resize(n + n + 1, vector<int>(n + n + 1, 0));
	int ans = 0;
	for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j) {
			cin >> mp[i][j];
			if (i > n && j > n) {
				ans += mp[i][j];
			}
		}
	}
	int MINIUM = 0x3f3f3f3f3f3f3f3f;
	MINIUM = min(
		min(min(mp[n + 1][n], mp[n + 1][1]), min(mp[n + n][1], mp[n + n][n])),
		min(min(mp[n][n + 1], mp[1][n + 1]), min(mp[1][n + n], mp[n][n + n])));
	cout << ans + MINIUM << "\n";
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