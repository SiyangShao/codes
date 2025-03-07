#include <bits/stdc++.h>

const int N = 10005;
const int M = 1e6 + 5;

int n, m, pa[M], pb[M], f[N * 2], ff[N * 2], sum[N * 2], ans[N * 2];
int vis[N * 2], dp[5005], dp2[5005];
std::map<int, std::pair<int, int>> mp;

inline int find(int x) {
	while (x != f[x]) x = f[x] = f[f[x]];
	return x;
}

inline int ffind(int x) {
	while (x != ff[x]) x = ff[x] = ff[ff[x]];
	return x;
}

int main() {
	scanf("%d%d", &n, &m);
	n *= 2;
	for (int i = 1; i <= m; ++i) scanf("%d%d", pa + i, pb + i);

	for (int i = 1; i <= n; ++i) sum[i] = 1;
	for (int i = 1; i <= n * 2; ++i) f[i] = ff[i] = i;
	for (int i = 1; i <= n; ++i) mp[i] = std::make_pair(1, 0);

	for (int i = m; i; --i) {
		if (ffind(pa[i]) != ffind(pb[i])) {
			int fx1 = find(pb[i] + n), fy1 = find(pa[i]);
			int fx2 = find(pa[i] + n), fy2 = find(pb[i]);
			int ffa = ffind(pa[i]), ffb = ffind(pb[i]);

			//printf("sum[%d]=%d\n", fx1, sum[fx1]);
			//printf("sum[%d]=%d\n", fy1, sum[fy1]);
			//printf("sum[%d]=%d\n", fx2, sum[fx2]);
			//printf("sum[%d]=%d\n", fy2, sum[fy2]);

			auto mpa = mp[ffa], mpb = mp[ffb];
			sum[fy1] += sum[fx1], sum[fy2] += sum[fx2];
			mp.erase(ffa);
			mp[ffb] = std::make_pair(sum[fy2], sum[fy1]);
			//for (auto [x, y] : mp) printf("%d:(%d,%d) ", x, y.first, y.second); puts("");

			std::bitset<5005> b;
			b[0] = 1;
			for (auto [x, y] : mp) {
				if (y.first && y.second) b |= (b << y.first) | (b << y.second);
				else if (y.first) b |= (b << y.first);
				else if (y.second) b |= (b << y.second);
			}
			if (b[n / 2]) {
				f[fx1] = fy1, f[fx2] = fy2, ff[ffa] = ffb;
				//printf("%d = [%d %d] is OK\n", i, pa[i], pb[i]);
			} else {
				sum[fy1] -= sum[fx1], sum[fy2] -= sum[fx2];
				mp[ffa] = mpa, mp[ffb] = mpb;
				//printf("%d = [%d %d] NO\n", i, pa[i], pb[i]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) ans[i] = 1;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (auto [x, y] : mp) {
		int bx = find(x + n);
		//printf("DBG %d %d:(%d %d)\n", x, bx, y.first, y.second);
		for (int j = 5000; ~j; --j) if (dp[j] != -1) {
			if (y.first && j + y.first <= 5000 && dp[j + y.first] == -1) dp[j + y.first] = x, dp2[j + y.first] = y.first;
			if (y.second && j + y.second <= 5000 && dp[j + y.second] == -1) dp[j + y.second] = bx, dp2[j + y.second] = y.second;
		}
	}
	for (int i = n / 2; i; i -= dp2[i]) {
		//printf("DBG dp[%d]=%d, op=%d\n", i, dp[i], find(dp[i] + n));
		ans[find(dp[i])] = 0, ans[find(dp[i] + n)] = 1;
	}
	//for (int i = 1; i <= n; ++i) printf("%d ", find(i)); puts("");
	for (int i = 1; i <= n; ++i) printf("%d", ans[find(i)]);
	puts("");
	return 0;
}
