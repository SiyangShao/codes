#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, x;
	int a[100010], b[100010];
	a[0] = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			if (a[i] > a[i - 1]) {
				flag = false;
			}
		}
		if (flag) {
			printf("YES\n");
		} else {
			if (n >= 2 * x) {
				printf("YES\n");
			} else {
				flag = true;
				sort(b + 1, b + 1 + n);
				for (int i = n - x + 1; i <= x; ++i) {
					if (b[i] != a[i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}
}