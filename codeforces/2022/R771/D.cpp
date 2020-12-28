#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1010;
int mp[N][N], vis[N][N];
int n, m, cn, cm, paint;
int dx[] = {-1, -1, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2};
int dy[] = {-1, 0, 1, 2, -1, 2, -1, 2, -1, 0, 1, 2};
bool check(int i, int j) {
	set<int> st;
	st.insert(mp[i][j]);
	st.insert(mp[i + 1][j]);
	st.insert(mp[i][j + 1]);
	st.insert(mp[i + 1][j + 1]);
	if (st.size() == 1 || (st.size() == 2 && st.count(-1) == 1)) {
		paint = -1;
		for (auto i : st) {
			paint = max(i, paint);
		}
		mp[i][j] = -1;
		mp[i + 1][j] = -1;
		mp[i][j + 1] = -1;
		mp[i + 1][j + 1] = -1;
		return true;
	}
	return false;
}
void solve() {
	memset(mp, -1, sizeof(mp));
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mp[i][j];
		}
	}
	queue<vector<int>> Q;
	vector<vector<int>> ans;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (!vis[i][j] && check(i, j)) {
				vis[i][j] = 1;
				ans.push_back({paint, i, j});
				Q.push({i, j});
			}
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		vis[cur[0]][cur[1]] = 1;
		for (int i = 0; i < 12; ++i) {
			int x = cur[0] + dx[i];
			int y = cur[1] + dy[i];
			if (x > 0 && x < n && y > 0 && y < m && vis[x][y] == 0 &&
				check(x, y)) {
				if (paint == -1)
					continue;
				// cout << paint << " " << x << " " << y << "\n";
				ans.push_back({paint, x, y});
				vis[x][y] = 1;
				Q.push({x, y});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] != -1) {
				cout << "-1\n";
				return;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
		cout << (*i)[1] << " " << (*i)[2] << " " << (*i)[0] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}