#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
const int MOD = 998244353;
LL f[N][2];

inline void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n + 5; i++)
		f[i][0] = f[i][1] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			f[0][1] = (f[0][1] * 2 + 1) % MOD;
			if (2 <= n)
				f[2][0] = f[2][0] * 2 % MOD;
		} else if (a[i] == 1) {
			f[1][0] = (f[1][0] * 2 + 1) % MOD;
			f[1][1] = (f[1][1] * 2 + f[0][1]) % MOD;
			if (3 <= n)
				f[3][0] = f[3][0] * 2 % MOD;
		} else {
			f[a[i]][0] = (f[a[i]][0] * 2 + f[a[i] - 2][1]) % MOD;
			f[a[i]][1] =
				(f[a[i]][1] * 2 + f[a[i] - 1][1] + f[a[i] + 2][0]) % MOD;
			if (a[i] + 2 <= n)
				f[a[i] + 2][0] = f[a[i] + 2][0] * 2 % MOD;
		}
	}
	LL res = 0;
	for (int i = 0; i <= n; i++)
		res = (res + f[i][0] + f[i][1]) % MOD;
	printf("%lld\n", res);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
