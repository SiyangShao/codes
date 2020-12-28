#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, h;
signed main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &h);
		int first = 0, second = 0;
		for (int i = 0, tmp; i < n; ++i) {
			scanf("%lld", &tmp);
			if (tmp > first) {
				second = first;
				first = tmp;
			} else if (tmp > second) {
				second = tmp;
			}
		}
		int t = 0;
		if (h <= first) {
			t = 1;
		} else {
			if (h % (first + second) == 0) {
				t = 2 * (h / (first + second));
			} else {
				if (h % (first + second) <= first) {
					t = 2 * (h / (first + second)) + 1;
				} else {
					t = 2 * (h / (first + second)) + 2;
				}
			}
		}
		printf("%lld\n", t);
	}
}