#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1010;
ll mp[N][N], vis[N][N];
ll n;
ll dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
inline bool check(ll x, ll y) {
	return vis[x - 1][y] == 0 && vis[x][y - 1] == 0 && vis[x + 1][y] == 0 &&
		   vis[x][y + 1] == 0;
}
inline void choose(ll x, ll y) {
	vis[x - 1][y] = 1;
	vis[x][y - 1] = 1;
	vis[x + 1][y] = 1;
	vis[x][y + 1] = 1;
}
void solve() {
	cin >> n;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> mp[i][j];
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (check(i, j)) {
				choose(i, j);
				res ^= mp[i][j];
			}
		}
	}
	cout << res << "\n";
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