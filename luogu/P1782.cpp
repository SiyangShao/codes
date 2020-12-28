#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
int n, m, c;
int q[N], f[N], dp[N];
int v, w, d;
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &v, &w, &d);
		for (int j = 0; j < v; j++) {
			for (int h = 0, t = 0, k = 0; k * v + j <= c; k++) {
				int x = dp[k * v + j] - k * w;
				while (h != t && x > f[t - 1])
					t--;
				q[t] = k;
				f[t++] = x;
				if (q[h] + d < k)
					h++;
				dp[k * v + j] = f[h] + k * w;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &v, &w, &d);
		for (int j = c; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				if (dp[j - k] + (v * k + w) * k + d > dp[j]) {
					dp[j] = dp[j - k] + (v * k + w) * k + d;
				}
			}
		}
	}
	printf("%d", dp[c]);
	return 0;
}