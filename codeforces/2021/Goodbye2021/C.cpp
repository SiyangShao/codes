#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n;
int dp[100][2000];
int a[100];
unordered_map<double, int> mp, evey;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int cnt = 0;
	mp.clear();
	memset(dp, 0, sizeof(dp));
	int num = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			int d = a[i] - a[j];
			double tmp = double(d) / double(i - j);
			// cout << tmp << " ";
			if (mp[tmp] == 0) {
				mp[tmp] = ++num;
			}
			int NUM = mp[tmp];
			dp[i][NUM] = max(dp[i][NUM], dp[j][NUM] + 1);
			cnt = max(cnt, dp[i][NUM]);
		}
		// cout << "\n";
	}

	// cout << cnt << " ";
	cout << n - cnt - 1 << "\n";
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