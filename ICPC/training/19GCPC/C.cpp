#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> mp[1005];
int vis[1005], flag[1005], dis[1005];
int sum, maxn;
int n, m;
int s, t, c;
void dfs(int a) {
	for (auto i : mp[a]) {
		if (dis[i.first] < dis[a] + i.second) {

			dis[i.first] = dis[a] + i.second;
			dfs(i.first);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> t >> c;
		flag[t]++;
		mp[s].push_back(make_pair(t, c));
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 0) {
			dfs(i);
		}
	}
	maxn = 0;
	for (int i = 1; i <= n; i++) {
		maxn = max(maxn, dis[i]);
	}
	cout << maxn << "\n";
}