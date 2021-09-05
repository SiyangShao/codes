#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n;
struct node {
	int power, i, number;
} k[100010];
bool cmp(node a, node b) { return a.power < b.power; }
signed main() {
	scanf("%lld", &_);
	while (_--) {
        memset(k,0,sizeof(k));
		scanf("%lld", &n);
		for (int i = 1, tmp; i <= n; ++i) {
			scanf("%lld", &tmp);
			k[i].i = i;
			k[i].number = tmp;
			for (int j = 0, q; j < tmp; ++j) {
				scanf("%lld", &q);
				if (k[i].power > q - j) {
					continue;
				} else {
					k[i].power = q - j + 1;
				}
			}
		}
		sort(k + 1, k + 1 + n, cmp);
		int ans = 0, now = 0;
		for (int i = 1; i <= n; ++i) {
			if (now < k[i].power) {
				ans += k[i].power - now;
				now = k[i].power + k[i].number;
			}
		}
		printf("%lld\n", ans);
	}
}