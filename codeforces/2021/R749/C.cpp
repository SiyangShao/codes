#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int n, m;
string s[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int pre[n + 10][m + 10];
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') {
				pre[i][j] =
					pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + 1;
			} else {
				pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
			}
		}
	}
	int q, l, r;
	cin >> q;
	while (q--) {
		cin >> l >> r;
		l--, r--;
		if ((pre[n - 1][r] - pre[0][r] - pre[n - 1][l] + pre[0][l]) != 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}