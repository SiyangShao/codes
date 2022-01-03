#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
int n;
vector<vector<int>> mp, L, C;
void solve() {
	cin >> n;
	mp.clear();
	mp.resize(n + n + 1, vector<int>(n + n + 1, 0));
	L.clear(), C.clear();
	int ans = 0;
	for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j) {
			cin >> mp[i][j];
			if (i > n && j > n) {
				ans += mp[i][j];
			}
		}
	}
	int MINIUM = -1;
	L = mp;
	C = mp;
	for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j) {
			L[i][j] += L[i - 1][j];
			C[i][j] += C[i][j - 1];
		}
	}

	for (int i = n + 1; i <= n + n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int tmp = min(C[i][j] - C[i][0], C[i][n] - C[i][j - 1]) +
					  min(L[i][j] - L[n][j], L[n + n][j] - L[i - 1][j]) -
					  mp[i][j];
			MINIUM = MINIUM == -1 ? tmp : min(MINIUM, tmp);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = n + 1; j <= n + n; ++j) {
			int tmp = min(C[i][j] - C[i][n - 1], C[i][n + n] - C[i][j - 1]) +
					  min(L[i][j] - L[0][j], L[n][j] - L[i - 1][j]) - mp[i][j];
			MINIUM = MINIUM == -1 ? tmp : min(MINIUM, tmp);
		}
	}
	cout << MINIUM + ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}