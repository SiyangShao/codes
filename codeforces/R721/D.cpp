#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a[100010], n, l[100010], sum[100010], pre[100010];
signed main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			l[i] = a[i];
            sum[i]=0;
            pre[i]=0;
		}
		sort(l + 1, l + 1 + n);
		auto m = unique(l + 1, l + 1 + n) - l - 1;
		int sum1 = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int k = lower_bound(l + 1, l + 1 + m, a[i]) - l;
			ans += sum1;
			sum[k] += pre[k];
			ans += sum[k];
			pre[k] = i;
			sum1 += sum[k];
		}
		printf("%lld\n", ans);
	}
}