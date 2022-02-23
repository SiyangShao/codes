#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n, k, a[15];
signed main() {
	scanf("%lld", &_);
	while (_--) {
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			a[i] = (int)pow(10, a[i]);
		}
		k++;
		int res = 0;
		for (int i = 1; i < n; ++i) {
			int d = a[i + 1] / a[i] - 1;
			if (k >= d) {
				res += a[i] * d;
				k -= d;
			} else {
				res += a[i] * k;
				k = 0;
			}
		}
		if (!k) {
			printf("%lld\n", res);
		} else {
			res += a[n] * k;
			printf("%lld\n", res);
		}
	}
}