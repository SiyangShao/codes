#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 7;
int n;
int a[N], b[N], c[N];
queue<int> d[N];
inline int lowbit(int x) { return x & (-x); }
void update(int x) {
	//区间最值更新
	int lx, i;
	while (x <= n) {
		c[x] = a[x];
		lx = lowbit(x);
		for (i = 1; i < lx; i <<= 1) {
			c[x] = max(c[x], c[x - i]);
		}
		x += lowbit(x);
	}
}
int query(int x, int y) {
	// 区间最大
	int ans = 0;
	while (y >= x) {
		ans = max(a[y], ans);
		y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y)) {
			ans = max(c[y], ans);
		}
	}
	return ans;
}
void solve() {
    cin >> n;
	for (int i = N - n; i <= N - 1; ++i) {
		while (!d[i].empty()) {
			d[i].pop();
		}
	}
	for(int i = 1; i<=n; ++i){
	    c[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = N - a[i];
		update(i);
		d[a[i]].push(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		b[i] = N - b[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (d[b[i]].empty()) {
			cout << "NO\n";
			return;
		}
		int now = d[b[i]].front();
		d[b[i]].pop();

		int num = query(1, now);
		if (b[i] < num) {
			cout << "NO\n";
			return;
		}
		a[now] = 0;
		update(now);
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}