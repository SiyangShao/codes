#include <bits/stdc++.h>

#define pb push_back
const int N = 1e5 + 5;

int n, vis[N], siz[N], maxx[N], sum, currt, crt;
std::vector<int> G[N];

void calcsiz(int x, int fa) {
  siz[x] = 1;
  maxx[x] = 0;
  for (int v : G[x]) if (v != fa && !vis[v]) {
  	calcsiz(v, x);
  	maxx[x] = std::max(maxx[x], siz[v]);
  	siz[x] += siz[v];
  }
  maxx[x] = std::max(maxx[x], sum - siz[x]);
  if (maxx[x] < maxx[crt]) crt = x;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) G[i].clear();
	memset(vis, 0, sizeof(int) * (n + 3));
	for (int i = 1; i <= n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		if (x) G[i].pb(x), G[x].pb(i);
		if (y) G[i].pb(y), G[y].pb(i);
	}
	maxx[0] = 1e9;
	sum = n;
	currt = 1;
	while (sum > 1) {
		crt = 0;
		calcsiz(currt, 0);
		//for (int i = 1; i <= n; ++i) printf("%d ", siz[i]); puts("");
		//for (int i = 1; i <= n; ++i) printf("%d ", maxx[i]); puts("");
		currt = crt;
		calcsiz(currt, 0);
		std::vector<int> alive;
		for (int x : G[currt]) if (!vis[x]) alive.pb(x);
		//printf("%d : ", currt);
		//for (int x : alive) printf("%d ", x);
		//printf("\n");
		if (alive.size() == 3) {
			printf("? %d %d\n", alive[0], alive[1]);
			fflush(stdout);
			int x; scanf("%d", &x);
			if (x == 0) {
				sum = siz[alive[0]];
				vis[currt] = 1;
				currt = alive[0];
			} else if (x == 1) {
				sum -= siz[alive[0]] + siz[alive[1]];
				vis[alive[0]] = vis[alive[1]] = 1;
			} else {
				sum = siz[alive[1]];
				vis[currt] = 1;
				currt = alive[1];
			}
		} else if (alive.size() == 2) {
			printf("? %d %d\n", alive[0], alive[1]);
			fflush(stdout);
			int x; scanf("%d", &x);
			if (x == 0) {
				sum = siz[alive[0]];
				vis[currt] = 1;
				currt = alive[0];
			} else if (x == 1) {
				printf("! %d\n", currt);
				fflush(stdout);
				return;
			} else {
				sum = siz[alive[1]];
				vis[currt] = 1;
				currt = alive[1];
			}
		} else if (alive.size() == 1) {
			printf("? %d %d\n", currt, alive[0]);
			fflush(stdout);
			int x; scanf("%d", &x);
			printf("! %d\n", x == 0 ? currt : alive[0]);
			fflush(stdout);
			return;
		} else {
			printf("! %d\n", currt);
			fflush(stdout);
			return;
		}
	}
	printf("! %d\n", currt);
	fflush(stdout);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}
