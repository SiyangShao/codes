#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N];
int n, m, mid, ans;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 2; i <= n; ++i) {
		c[i] = c[i - 1] + b[i - 1] - a[i - 1];
	}
	sort(c + 1, c + 1 + n);
	mid = c[(n + 1) / 2];
	m = 0 - mid;
	for (int i = 1; i <= n; ++i) {
		ans += abs(c[i] + m);
	}
	cout << ans;
}