#include <bits/stdc++.h>
using namespace std;
int fa[150010], n, k, ans;
void init() {
	for (int i = 1; i <= n * 3; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
int main() {
	cin >> n >> k;
	init();
	for (int x, y, tmp; k; k--) {
		cin >> tmp >> x >> y;
		if (x > n || y > n) {
			ans++;
			continue;
		}
		if (tmp == 1) {
			if (find(x+n)==find(y)||find(x)==find(y+n)) {
				ans++;
			} else {
				unionSet(x, y);
				unionSet(x + n, y + n);
				unionSet(x + n + n, y + n + n);
			}
		} else {
			if (x == y) {
				ans++;
				continue;
			} else if (find(x)==find(y)||find(x)==find(y+n)) {
				ans++;
			} else {
				unionSet(x, y + n + n);
				unionSet(x + n, y);
				unionSet(x + n + n, y + n);
			}
		}
	}
	cout << ans;
}