#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int t, n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
string mp[N];
inline bool check(pair<int, int> p) {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int x = p.first + dx[i], y = p.second + dy[i];
		if (x < 0 || x >= n || y < 0 || y >= m)
			continue;
		if (mp[x][y] == '.')
			cnt++;
	}
	return cnt <= 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> mp[i];
		}
		pair<int, int> s;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mp[i][j] == 'L') {
					s = {i, j};
					break;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push(s);
		while (!q.empty()) {
			auto now = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				auto x = now.first + dx[i], y = now.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m) {
					continue;
				}
				if (mp[x][y] == '+' || mp[x][y] == 'L' || mp[x][y] == '#') {
					continue;
				}
				if (check({x, y})) {
					mp[x][y] = '+';
					q.push({x, y});
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << mp[i] << "\n";
		}
	}
}