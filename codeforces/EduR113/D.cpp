#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int x[N], y[N], a[N], b[N], cx[N], cy[N];
map<int, int> mp1[N], mp2[N];
int n, m, k, t, ans, p, q;
signed main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
			cx[i] = 0;
			mp1[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lld", &y[i]);
			cy[i] = 0;
			mp2[i].clear();
		}
		ans = 0;
		for (int i = 1; i <= k; i++) {
			scanf("%lld%lld", &p, &q);
			a[i] = upper_bound(x + 1, x + 1 + n, p) - x - 1;
			b[i] = upper_bound(y + 1, y + 1 + m, q) - y - 1;
			if (x[a[i]] != p || y[b[i]] != q) {
				if (x[a[i]] == p) {
					ans += cy[b[i]]++ - mp1[a[i]][b[i]]++;
				} else if (y[b[i]] == q) {
					ans += cx[a[i]]++ - mp2[b[i]][a[i]]++;
				}
			}
		}
		printf("%lld\n", ans);
	}
}
