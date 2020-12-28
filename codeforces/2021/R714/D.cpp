#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int n, i;
} a[200010];
int _, p, n, b[200010], vis[200010];
bool cmp(node x, node y) { return x.n < y.n; }
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		memset(vis, 0, sizeof(vis));
		cin >> n >> p;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			a[i].n = b[i];
			a[i].i = i;
		}
		sort(a + 1, a + 1 + n, cmp);
		int ans = 0, rest = n - 1;
		for (int i = 1; i <= n; i++) {
			if (a[i].n > p)
				break;
			if (vis[a[i].i])
				continue;
			int l = a[i].i, r = a[i].i;
			while (l > 1 && !vis[l] && (b[l - 1] % a[i].n == 0))
				l--;
			while (r < n && !vis[r] && (b[r + 1] % a[i].n == 0))
				r++;
			for (int i = l; i <= r; i++) {
				vis[i] = 1;
			}
			rest -= r - l;
			ans += (r - l) * a[i].n;
		}
		ans += rest * p;
		cout << ans << "\n";
	}
}