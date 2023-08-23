#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 500;

int n;
vector<int> g[maxn];
vector<int> cnt0, cnt1;
int ans[maxn];
unordered_map<int, vector<int>> mp;

void init() {
	for (int i = 1; i < maxn; i++) {
		mp[__lg(i) + 1].push_back(i);
	}
}

void dfs(int now, int fa, int dep) {
	if (dep % 2 == 0)
		cnt0.push_back(now);
	else
		cnt1.push_back(now);
	for (int &to : g[now]) {
		if (to == fa)
			continue;
		dfs(to, now, dep + 1);
	}
}

void solve() {
	cin >> n;
	cnt0.clear();
	cnt1.clear();
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
		g[i].clear();
		ans[i] = -1;
	}
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 0);

	int ptr = 0;
	while (ptr < cnt0.size()) {
		int lg = __lg(cnt0.size() - ptr) + 1;
		for (int &it : mp[lg]) {
			if (it > n)
				break;
			ans[cnt0[ptr++]] = it;
			s.erase(it);
		}
	}

	for (int &it : cnt1) {
		ans[it] = (*s.begin());
		s.erase(s.begin());
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	init();
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}