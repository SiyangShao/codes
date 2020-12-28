#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6 + 7;
int phi[MAXN], vis[MAXN], cnt, pri[MAXN];
void init() {
	phi[1] = 1;
	vis[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		if (!vis[i]) {
			phi[i] = i - 1;
			pri[cnt++] = i;
		}
		for (int j = 0; j < cnt; ++j) {
			if (1ll * i * pri[j] >= MAXN)
				break;
			vis[i * pri[j]] = 1;
			if (i % pri[j]) {
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			} else {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
		}
	}
}
int n, e, t = 1;
int a[MAXN];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	init();
	vis[1] = 1;
	while (t--) {
		cin >> n >> e;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int ans = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (vis[a[i]]) {
				continue;
			}
			cnt1 = 0, cnt2 = 0;
			for (int t = i + e; t <= n; t += e) {
				if (a[t] == 1) {
					cnt2++;
				} else {
					break;
				}
			}
			for (int t = i - e; t > 0; t -= e) {
				if (a[t] == 1) {
					cnt1++;
				} else {
					break;
				}
			}
			ans += (cnt1 + 1) * (cnt2 + 1) - 1;
		}
		cout << ans << "\n";
	}
}