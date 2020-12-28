#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int mx = 0;
	vector<int> cnt(n + 1, 0), pos(n + 1, 0), a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i], cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
		pos[a[i]] = i;
	}
	if (mx > 1) {
		puts("YES");
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		if (a[i] == i + 1)
			continue;
		int nxt = pos[i + 1], now = i, lst = n - 1;
		if (nxt == n - 1)
			lst = n - 2;
		int tmp = a[lst];
		a[lst] = a[i];
		pos[a[i]] = lst;
		a[now] = i + 1;
		pos[i + 1] = now;
		a[nxt] = tmp;
		pos[tmp] = nxt;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			puts("NO");
			return;
		}
	}

	puts("YES");
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}