#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> ans(n + 1, 0), vis(n + 1, 0);
	int ask = 0;
	for (int i = 1, tmp; i <= n; ++i) {
		if (!vis[i]) {
			cout << "? " << i << endl;
			cin >> tmp;
			ask++;
			vector<int> r;
			while (vis[tmp] == 0) {
				vis[tmp] = 1;
				r.emplace_back(tmp);
				cout << "? " << i << endl;
				cin >> tmp;
				ask++;
			}
			vis[tmp] = 1;
			int round = r.size();
			for (int i = 0; i < round; ++i) {
				ans[r[(ask + i - 1) % round]] = r[(ask - round + i) % round];
			}
		}
	}
	cout << "!";
	for (int i = 1; i <= n; ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
}
signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}