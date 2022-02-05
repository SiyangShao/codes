#include <bits/stdc++.h>
#define int long long
using namespace std;
int _;
int n, k, now, ans, tag;
signed main() {
	scanf("%lld", &_);
	while (_--) {
		now = 1, ans = 0, tag = 1;
		scanf("%lld%lld", &n, &k);
		while (now < n) {
			ans++;
			now += tag;
			tag <<= 1ll;
			if (tag > k) {
				ans += (n - now + k - 1) / k;
				break;
			}
		}
		printf("%lld\n", ans);
	}
}