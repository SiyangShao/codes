#include <bits/stdc++.h>
const int MAXN = 100005;
using namespace std;
int sta[MAXN], num[MAXN];
int n, m, a, b, at, bt;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> sta[i];
		if (sta[i])
			a++;
		else
			b++;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (sta[u] != sta[v]) {
			if (num[u] == 0) {
				if (sta[u] == 1)
					at++;
				else
					bt++;
			}
			if (num[v] == 0) {
				if (sta[v] == 1)
					at++;
				else
					bt++;
			}
			num[u]++;
			num[v]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		if (sta[i] == 1) {
			if (num[i] == 0)
				ans += a - 1 + bt * 2 + (b - bt) * 3;
			else
				ans += num[i] + (a - 1) + 2 * (b - num[i]);
		} else {
			if (num[i] == 0)
				ans += b - 1 + at * 2 + (a - at) * 3;
			else
				ans += num[i] + (b - 1) + 2 * (a - num[i]);
		}
		if (i != n)
			cout << ans << " ";
		else
			cout << ans << '\n';
	}
	return 0;
}