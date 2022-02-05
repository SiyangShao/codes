#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int _, n, k, ans, cnt;
int a[100010];
vector<int> node[100010];
void dfs(int x, int root) {
	for (auto i : node[x]) {
		if (i == root) {
			continue;
		} else {
			dfs(i, x);
			a[x] ^= a[i];
		}
	}
	if (a[x] == ans) {
		cnt++;
		a[x] = 0;
	}
}
void solve() {
	scanf("%d%d", &n, &k);
	ans = 0;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ans ^= a[i];
	}
	for (int i = 1, j, k; i < n; ++i) {
		scanf("%d%d", &j, &k);
		node[j].pb(k);
		node[k].pb(j);
	}
	if (ans == 0) {
		puts("YES");
	} else {
		if (k == 2) {
			puts("NO");
		} else {
			dfs(1, 0);
			if (cnt >= 3) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
}
int main() {
	scanf("%d", &_);
	while (_--) {
		memset(node, 0, sizeof(node));
		solve();
	}
}