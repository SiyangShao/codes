#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
int a[300010], b[300010], pre[300010], dp[300010];
void solve() {
	int n;
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[n] = 0;
	int loc = n - 1;
	per(i, n) {
		int id = i + 1;
		int val = dp[id];
		int to = i + b[i];
		int ri = to - a[to] + 1;
		while (ri <= loc) {
			dp[loc] = val + 1;
			pre[loc] = id;
			loc--;
		}
	}
	int ans = dp[0];
	if (ans >= 0x3f3f3f3f / 2) {
		cout << -1 << "\n";
		return;
	}
	vector<int> v;
	int cur = 0;
	while (cur != n) {
		v.push_back(cur);
		cur = pre[cur];
	}
	reverse(all(v));
	cout << ans << "\n";
	rep(i, v.size()) {
		if (i > 0)
			cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
