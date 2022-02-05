#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int vis[N];
inline void solve() {
	int n;
	cin >> n;
	vector<int> res;
	memset(vis, 0, sizeof(vis));
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> tmp;
		if (tmp <= n && tmp >= 1 && vis[tmp] == 0) {
			vis[tmp] = 1;
		} else {
			res.push_back(tmp);
		}
	}
	sort(res.begin(), res.end(), greater<int>());
	int now = n;
	int ans = 0;
	for (auto i : res) {
		while (vis[now]) {
			now--;
		}
		if (now > (i - 1) / 2) {
			ans = -1;
			break;
		} else {
			vis[now] = 1;
			ans++;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}